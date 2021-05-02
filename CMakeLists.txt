cmake_minimum_required(VERSION 3.17)
project(awv9p5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(awv9p5
        awv9p5.cpp
        CounterTop.cpp
        CounterTop.h
        LinkedList.cpp
        LinkedList.h
        )
