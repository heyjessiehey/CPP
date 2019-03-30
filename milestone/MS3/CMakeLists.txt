cmake_minimum_required(VERSION 3.9)
project(MS3)

set(CMAKE_CXX_STANDARD 11)

add_executable(MS3
        ErrorState.cpp
        ErrorState.h
        ms3_tester.cpp
        MyProduct.cpp
        MyProduct.h
        Product.cpp
        Product.h)
