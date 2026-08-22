# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

"Killer Fox" — a top-down action game built on raylib. A learning project (first C++
codebase), so idiomatic-C++ concerns are secondary to keeping the game working.

## Build

Windows/MSVC only. There is no CMake, no test suite, and no linter configured.

- **Solution:** `PotatoEngine.sln`, single project `PotatoEngine/PotatoEngine.vcxproj`
- **Toolset:** v143, configurations `Debug|Release` × `Win32|x64`
- **Language standard:** unset in the project file, so it defaults to C++14
- **Warnings:** `Level3`

```
msbuild PotatoEngine.sln /p:Configuration=Release /p:Platform=x64
```

raylib is resolved through **vcpkg's user-wide MSBuild integration** — the `.vcxproj`
contains no `AdditionalIncludeDirectories` or `AdditionalDependencies` for it. If
`raylib.h` fails to resolve, the fix is `vcpkg integrate install`, not a project edit.

**Working directory matters.** `GameResources.cpp` loads textures via relative paths
(`assets/...`), and the assets live in `PotatoEngine/assets/`. The build output lands
elsewhere (`x64/Debug/`, `Release/`), so launching the `.exe` from its output directory
fails to find textures. Run with the working directory set to `PotatoEngine/` (which is
what Visual Studio's F5 does by default).

## Architecture

### Rendering stack (bottom to top)

Each layer wraps exactly one of the layer below it:

- **`Sprite`** — a `Texture2D*` plus position/scale/rotation/color.
- **`AnimatedSprite`** — adds a `framesX × framesY` grid and `drawFrame(int)`. Also owns
  horizontal flip via `rightleft` (a `float` that is only ever `±1`, multiplied into the
  source rect width; raylib flips on negative width).
- **`Animation`** — a frame range `[startFrame, endFrame]` over one `AnimatedSprite`,
  plus playback speed and a `looping` flag. Non-looping animations latch `finished`,
  which is how the player's attack and roll states know when to return to `MOVE`.
- **`AnimationManager`** — a name→`Animation*` map with one `activeAnimation`. Every
  `Entity` owns one. All position/color/flip calls forward to the active animation only.

### Entity hierarchy

`Entity` is the base for both `Player` and `Enemy`. It holds position, velocity,
direction, `collisionRec`, the `AnimationManager`, and window bounds.

**`Entity::update()` hardcodes the animation names `"run"` and `"idle"`.** Any subclass
that calls the base `update()` must register animations under exactly those two names —
this is what `Goblin` and `Slime` do. `Player` does *not* use them; it overrides
`update()` entirely and duplicates the movement/collision logic, because it needs
directional animation names instead.

### Player

A three-state machine (`PlayerState::MOVE | ROLL | ATTACK`) in `Player.h`, dispatched by
a `switch` in `Player::update()` to `move()` / `roll()` / `attack()`.

Animations follow a **`{action}_{direction}` naming convention** — `run_left`,
`attack_up`, `roll_down`, `idle_right` — selected by inspecting the sign of `direction.x`
then `direction.y`. All of them index into a single 60-frame horizontal strip
(`assets/Player.png`) with hardcoded index ranges registered in the `Player` constructor.
Adding a player animation means adding frames to that strip and a matching
`animations.add(...)` line with the right indices.

`ROLL` grants i-frames: `Enemy::update()` skips damage when the player's state is `ROLL`
or when `isHurting()` is true.

### Enemies — Prototype + Factory

`EnemyFactory` constructs one prototype per type (`"goblin"`, `"slime"`) in its
constructor and hands out `Clone()`s. `EnemyManager::create()` then calls
`setPosition` / `setTarget` / `setWindow` / `loadAnimations` on the clone.

**Load-bearing invariant:** `loadAnimations()` is called on the *clone*, never on the
prototype. `Clone()` is `new Goblin(*this)` — a shallow copy — so the copied
`AnimationManager` would share raw `Animation*` pointers with every other clone. It is
only safe because the prototypes' animation maps are always empty. Do not call
`loadAnimations()` on a prototype.

Adding an enemy type currently requires a new `.h`, a new `.cpp`, and an
`EnemyFactory` constructor/destructor edit. `Goblin` and `Slime` differ only in speed,
points, and texture-name prefix.

Killed enemies are flagged `isAlive = false` but are never erased from
`EnemyManager::enemies`; they are skipped, not removed.

### Textures

One global `TextureManager textureManager` (declared `extern` in `GameResources.h`,
defined in `GameResources.cpp`). All loading is centralized in `LoadTextures()`.

**Construction order is a real constraint:** `Player`'s constructor calls
`textureManager.get()`, so `LoadTextures()` must run before any `Player` is constructed.
`main.cpp` satisfies this by declaring `Player knight` after the `LoadTextures()` call.
Making a `Player` (or anything else that pulls textures in its constructor) a global
would break this silently.

## Conventions and known traps

- **Ownership is raw `new` throughout**, with no smart pointers. `AnimationManager` has
  no destructor, so animations and their sprites are not freed. Enemy spawns leak.
- **Map keys are `const char*`, not `std::string`**, in both `AnimationManager` and
  `TextureManager` — lookups compare *pointer addresses*, not text. This works across
  translation units only because the Release configs set `EnableCOMDATFolding`
  (`/OPT:ICF`) to merge identical literals; the Debug configs do not. Keep this in mind
  when adding animation or texture names used from more than one `.cpp`.
- **Map lookups use `operator[]`**, so an unknown key silently inserts a default entry
  (a zeroed `Texture2D`, or a null `Animation*`) rather than reporting an error. A typo'd
  animation name produces a null-deref on the next `update()`; a typo'd texture name
  produces an invisible sprite.
- **`position` is the top-left corner, but `getPosition()` returns the center**
  (`Entity` and `Sprite` both do this). `setPosition(getPosition())` is not a no-op.
- **`update()` methods draw.** `Player::update()` and `Enemy::update()` call
  `DrawRectangleLines` for the debug collision boxes, but `main.cpp` runs `update()`
  before `BeginDrawing()`, so those debug rectangles do not currently render. The
  toggles in `main.cpp` are commented out for this reason.
- Getters are generally non-`const`, so `const Entity&` is not usable.

## Other agent configs

`~/.codex/config.toml` and `~/.gemini/settings.json` exist on this machine. To pull
their user-level items (MCP servers, slash commands, subagents, skills, instructions)
into Claude Code, reply `/import` to scan and list what's importable, then
`/import --yes=<digest>` with the digest from the scan output to apply. If `/import`
isn't available on this surface, run `claude import` from a terminal instead.
