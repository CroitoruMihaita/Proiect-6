cmake_minimum_required(VERSION 3.2)
project(Proiect6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c functii.c header.h)
add_executable(Proiect6 ${SOURCE_FILES} header.h main.c functii.c)