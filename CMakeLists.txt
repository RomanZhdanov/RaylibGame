cmake_minimum_required(VERSION 3.21)
project(PotatoEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.5
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(PotatoEngine
  PotatoEngine/main.cpp
  PotatoEngine/AnimatedSprite.h
  PotatoEngine/AnimatedSprite.cpp
  PotatoEngine/Animation.h
  PotatoEngine/Animation.cpp
  PotatoEngine/AnimationManager.h
  PotatoEngine/AnimationManager.cpp
  PotatoEngine/Enemy.h
  PotatoEngine/Enemy.cpp
  PotatoEngine/EnemyFactory.h
  PotatoEngine/EnemyFactory.cpp
  PotatoEngine/EnemyManager.h
  PotatoEngine/EnemyManager.cpp
  PotatoEngine/Entity.h
  PotatoEngine/Entity.cpp
  PotatoEngine/GameResources.h
  PotatoEngine/GameResources.cpp
  PotatoEngine/Goblin.h
  PotatoEngine/Goblin.cpp
  PotatoEngine/Player.h
  PotatoEngine/Player.cpp
  PotatoEngine/Slime.h
  PotatoEngine/Slime.cpp
  PotatoEngine/Sprite.h
  PotatoEngine/Sprite.cpp
  PotatoEngine/TextureManager.h
  PotatoEngine/TextureManager.cpp
)

target_include_directories(PotatoEngine PRIVATE PotatoEngine)
target_link_libraries(PotatoEngine PRIVATE raylib)
