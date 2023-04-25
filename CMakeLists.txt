cmake_minimum_required(VERSION 3.23)
project(bprogramming C)

set(CMAKE_C_STANDARD 11)

add_executable(bprogramming main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)
