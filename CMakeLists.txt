cmake_minimum_required(VERSION 3.21)
project(PotatoEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
  src/main.cpp
  src/AnimatedSprite.h
  src/AnimatedSprite.cpp
  src/Animation.h
  src/Animation.cpp
  src/AnimationManager.h
  src/AnimationManager.cpp
  src/Enemy.h
  src/Enemy.cpp
  src/EnemyFactory.h
  src/EnemyFactory.cpp
  src/EnemyManager.h
  src/EnemyManager.cpp
  src/Entity.h
  src/Entity.cpp
  src/GameResources.h
  src/GameResources.cpp
  src/Goblin.h
  src/Goblin.cpp
  src/Player.h
  src/Player.cpp
  src/Slime.h
  src/Slime.cpp
  src/Sprite.h
  src/Sprite.cpp
  src/TextureManager.h
  src/TextureManager.cpp
  src/WindowDimensions.h
)

target_include_directories(PotatoEngine PRIVATE src)
target_link_libraries(PotatoEngine PRIVATE raylib)

add_custom_command(TARGET PotatoEngine POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${CMAKE_CURRENT_SOURCE_DIR}/src/assets"
          "$<TARGET_FILE_DIR:PotatoEngine>/assets"
  COMMENT "Copying assets next to the executable"
)
