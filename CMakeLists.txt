cmake_minimum_required(VERSION 3.23)
project(hashCMZI)

set(CMAKE_CXX_STANDARD 20)



add_executable(hashCMZI main.cpp md5.cpp md5.h)

find_package(OpenSSL REQUIRED)
target_link_libraries(hashCMZI OpenSSL::SSL)
