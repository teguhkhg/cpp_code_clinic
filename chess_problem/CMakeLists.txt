cmake_minimum_required(VERSION 2.6)
project(chess_problem)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
)

add_executable(n_queens src/n_queens.cpp)
add_executable(knights_tour src/knights_tour.cpp)