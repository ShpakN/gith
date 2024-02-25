cmake_minimum_required(VERSION 3.26)
project(gith C)

set(CMAKE_C_STANDARD 11)

add_executable(gith main.c
        vector.h)
