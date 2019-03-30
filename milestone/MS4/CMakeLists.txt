cmake_minimum_required(VERSION 3.9)
project(MS4)

set(CMAKE_CXX_STANDARD 11)

add_executable(MS4
        Allocator.cpp
        ms4_tester.cpp
        MyProduct.cpp
        MyProduct.h iProduct.h)
