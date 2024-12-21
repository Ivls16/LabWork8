cmake_minimum_required(VERSION 3.29)
project(Task1)

set(CMAKE_CXX_STANDARD 14)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

add_executable(Task1
        main.cpp
        product_functions.cpp
        product.h
        algorithms.cpp
        binary.cpp
        product_functions.h)
