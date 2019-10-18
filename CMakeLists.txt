cmake_minimum_required(VERSION 3.14)
project(StackFun)

set(CMAKE_CXX_STANDARD 99)

include_directories(.)

add_executable(StackFun
        fake_picture.txt
        stack_ll.h floodfill.c stack_ll.c makefile)
