cmake_minimum_required(VERSION 3.22)
project(GraphicsLibray C)

set(CMAKE_C_STANDARD 99)

add_executable(GraphicsLibray main.c GUI/Graphics.h GUI/Graphics.c GameLoop/GameLoop.h GameLoop/GameLoop.c)
