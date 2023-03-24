cmake_minimum_required(VERSION 3.24)
project(1testePA)

set(CMAKE_CXX_STANDARD 23)

add_executable(1testePA main.cpp Student.cpp Student.h Grade.cpp Grade.h Discipline.cpp Discipline.h)
