cmake_minimum_required(VERSION 3.9)
project(MS5)

set(CMAKE_CXX_STANDARD 11)

add_executable(MS5
        Allocator.cpp
        Date.cpp
        Date.h
        ErrorState.cpp
        ErrorState.h
        iProduct.h
        ms5_tester.cpp
        Product.cpp
        Product.h Perishable.cpp Perishable.h)
