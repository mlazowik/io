cmake_minimum_required(VERSION 2.8)
project(io)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(SOURCE_FILES
    io/descriptor.h
    io/io_events.cpp
    io/io_events.h)

add_library(io ${SOURCE_FILES})

target_include_directories(io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})