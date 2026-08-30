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

The build copies `assets/` next to the executable, and the executable switches to its own
directory on startup, so it can be launched from anywhere:

```
./build/Release/PotatoEngine
```

## Controls

|                          | Keyboard                      | Gamepad             |
| ------------------------ | ----------------------------- | ------------------- |
| Move                     | `W` `A` `S` `D` / arrow keys  | left stick / d-pad  |
| Attack                   | `Space`                       | X / square          |
| Roll (i-frames)          | `Z`                           | A / cross           |
| Restart after game over  | `R`                           | A / cross           |

Control follows whichever device you last used — press a key and it's the keyboard, use
the stick or a button and it's the gamepad. Merely having a pad connected doesn't switch
anything, because on Linux raylib reports a laptop touchpad as a gamepad, and switching on
presence would lock the keyboard out.

## Layout

- `src/` — all sources
- `assets/` — sprite sheets, copied next to the executable at build time
- `CHANGELOG.md` — release notes
