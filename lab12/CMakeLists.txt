cmake_minimum_required(VERSION 3.8)
project(lab12)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bus.cpp Bus.h Driver.h)
add_executable(main ${SOURCE_FILES})