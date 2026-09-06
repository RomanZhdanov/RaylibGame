# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.2.0] - 2026-09-06

### Added

- Health and damage replace the fixed four-life system. The player starts at 10 HP,
  each enemy type deals its own damage, and the HUD shows `HP` instead of `Lives`
- Enemies now have health and survive multiple hits instead of dying to a single one
- `goblin-boss` — a tougher, slower, purple goblin worth 1000 points
- Enemies spawn from all four screen edges instead of only the bottom centre
- Weighted random enemy selection through a shuffle bag, so the mix stays close to its
  intended ratio instead of drifting into long runs of one type
- Randomised spawn interval between 0.5 and 2 seconds, replacing a fixed 2-second timer
- A cap on how many enemies can be alive at once, starting at one and rising by one every
  ten seconds, so difficulty ramps over a run
- A dedicated hurtbox for the player, separate from its collision box, so contact damage
  no longer triggers on the full sprite footprint

### Changed

- Enemy stats — health, damage, speed, points, scale and colour — are constructor
  arguments, so a new variant is a line in `EnemyFactory` rather than a new class
- Enemies stop moving while they are being hit
- A single attack registers at most once per enemy, instead of once per overlapping frame
- Roll speed lowered from 2.8x to 2.5x walking speed
- Restarting after a death now also resets the enemy cap and both spawn timers
- Drawing moved out of `update()` into `draw()` on `Entity`, `Player` and `Enemy`

### Fixed

- Sprites, animations and enemies are no longer leaked. `AnimatedSprite` is shared
  ownership, `AnimationManager` frees its animations, `Entity` has a virtual destructor,
  and dead enemies are erased and deleted rather than kept in the list forever

## [0.1.1] - 2026-08-30

### Added

- Arrow keys as an alternative to `W` `A` `S` `D` for movement

### Fixed

- Gamepad detection on Linux no longer locks the keyboard out. raylib reports any
  input device with absolute axes as a gamepad — a laptop touchpad qualifies — so a
  "connected" pad that never actually sends input could take over and leave the player
  unable to move. Input now follows whichever device was last used rather than whichever
  ones are present
- Assets now load when the game is launched from a directory other than its own

## [0.1.0] - 2026-08-23

Initial release of PotatoEngine, a 2D game built with raylib.

### Added

- Sprite rendering via `Sprite` and `AnimatedSprite`, driven by frame-based
  `Animation` and `AnimationManager`
- `TextureManager` for loading and caching textures, with `GameResources`
  providing shared access to game-wide assets
- `Entity` base type with a playable `Player`
- Enemy system: abstract `Enemy` type with `Goblin` and `Slime` implementations,
  constructed through `EnemyFactory` and driven by `EnemyManager`
- Configurable window sizing through `WindowDimensions`
- CMake build that fetches raylib 5.5 automatically via `FetchContent`, so no
  manual dependency setup is required
- `CMakePresets.json` with Ninja Multi-Config presets for local Debug and
  Release builds
- Install rules that stage the executable alongside its `assets/` directory
- Prebuilt binaries for Linux (x64), Windows (x64) and macOS (universal),
  published as archives with SHA-256 checksums

[Unreleased]: https://github.com/RomanZhdanov/RaylibGame/compare/v0.2.0...HEAD
[0.2.0]: https://github.com/RomanZhdanov/RaylibGame/compare/v0.1.1...v0.2.0
[0.1.1]: https://github.com/RomanZhdanov/RaylibGame/compare/v0.1.0...v0.1.1
[0.1.0]: https://github.com/RomanZhdanov/RaylibGame/releases/tag/v0.1.0
