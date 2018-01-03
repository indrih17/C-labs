cmake_minimum_required(VERSION 3.8)
project(lab11-2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Date.cpp Date.h)
add_executable(main ${SOURCE_FILES})