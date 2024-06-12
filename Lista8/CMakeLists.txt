cmake_minimum_required(VERSION 3.5)

project(nienazwane LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zad1 zad1.cpp
    zad1.cpp)
add_executable(zad2 main.cpp timer.cpp timer.h)


