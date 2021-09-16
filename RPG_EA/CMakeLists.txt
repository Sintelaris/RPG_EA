cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Game.cpp Game.h Character.cpp Character.h Map.cpp Map.h)
