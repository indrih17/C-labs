cmake_minimum_required(VERSION 3.8)
project(lab09-1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ComplexNumber.cpp ComplexNumber.h)
add_executable(main ${SOURCE_FILES})