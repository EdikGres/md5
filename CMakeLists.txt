cmake_minimum_required(VERSION 3.23)
project(hashCMZI)

set(CMAKE_CXX_STANDARD 20)

add_executable(hashCMZI main.cpp md5.c md5.h)
