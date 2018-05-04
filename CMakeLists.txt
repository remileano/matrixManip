cmake_minimum_required(VERSION 3.10)
project(matrixmanip)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(matrixmanip
        main.cpp
        Makefile
        matrix.cpp
        matrix.h
        mysavefile.txt
        mysavefile2.txt
        readme.txt)
