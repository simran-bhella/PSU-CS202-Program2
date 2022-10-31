cmake_minimum_required(VERSION 3.16)
project(Program2_new_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Program2_new_1
        dll.h
        dll.tpp
        main.cpp
        reservation.cpp
        reservation.h
        things.cpp
        things.h)
