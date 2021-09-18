cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Game.cpp Game.h Map.cpp Map.h Character.cpp Character.h Item.cpp Item.h)
