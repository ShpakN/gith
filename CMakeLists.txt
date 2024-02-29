cmake_minimum_required(VERSION 3.26)
project(gith C)

set(CMAKE_C_STANDARD 11)

add_executable(gith libs/data_structures/vector/main.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vector.c
        libs/data_structures/vector/vectorVoid.h
        libs/data_structures/vector/vectorVoid.c
)
