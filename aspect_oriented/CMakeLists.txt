cmake_minimum_required(VERSION 2.6)
project(aspect_oriented)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
)

add_executable(plus src/plus.cpp)
add_executable(find_by_id src/find_by_id.cpp)