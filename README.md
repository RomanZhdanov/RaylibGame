# Killer Fox / PotatoEngine

A small top-down action game built on [raylib](https://www.raylib.com/) 5.5.

This is a learning project. I'm a C# developer using it to get into C++ — the goal is to
learn the language and the raylib API, not to ship an engine.

## Build

raylib is fetched and built from source via CMake's `FetchContent`, so there's nothing to
install system-wide:

```
cmake --preset default          # configure — only needed once
cmake --build --preset release  # or --preset debug
```

On Linux you do need the usual X11/ALSA/GL development packages that raylib itself links
against — see the `Install raylib system dependencies` step in
[`.github/workflows/ci.yml`](.github/workflows/ci.yml) for the exact list.

## Run

Textures are loaded through paths relative to the working directory, and the build copies
`assets/` next to the executable, so run it from its own output directory:

```
(cd build/Release && ./PotatoEngine)
```

## Controls

|                          | Keyboard        | Gamepad             |
| ------------------------ | --------------- | ------------------- |
| Move                     | `W` `A` `S` `D` | left stick / d-pad  |
| Attack                   | `Space`         | X / square          |
| Roll (i-frames)          | `Z`             | A / cross           |
| Restart after game over  | `R`             | A / cross           |

A gamepad is auto-detected and takes over from the keyboard when one is connected.

## Layout

- `src/` — all sources
- `assets/` — sprite sheets, copied next to the executable at build time
- `CHANGELOG.md` — release notes
