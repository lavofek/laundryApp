cmake_minimum_required(VERSION 4.1)
project(laundryApp C)

set(CMAKE_C_STANDARD 11)

add_executable(laundryApp main.c
        family.c
        family.h
        storage.c
        storage.h
)
