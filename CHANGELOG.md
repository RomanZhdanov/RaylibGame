# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

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

[Unreleased]: https://github.com/RomanZhdanov/RaylibGame/compare/v0.1.0...HEAD
[0.1.0]: https://github.com/RomanZhdanov/RaylibGame/releases/tag/v0.1.0
