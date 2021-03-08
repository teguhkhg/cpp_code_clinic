cmake_minimum_required(VERSION 2.6)
project(game_of_life)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
)

add_executable(game_of_life src/game_of_life.cpp)