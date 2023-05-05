cmake_minimum_required(VERSION 3.24)
project(Lab07_Mini_GDB C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab07_Mini_GDB  GDBassign.c blowfish.c blowfish.h)
