cmake_minimum_required(VERSION 2.6)
project(n_queens)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
)

add_executable(${PROJECT_NAME} src/main.cpp)