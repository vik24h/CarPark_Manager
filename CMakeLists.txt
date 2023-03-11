cmake_minimum_required(VERSION 3.21)
project(oop_lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(oop_lab5)

add_executable(oop_lab5
        oop_lab5/Controller.cpp
        oop_lab5/Controller.h
        oop_lab5/Domain.cpp
        oop_lab5/Domain.h
        oop_lab5/InFileRepository.cpp
        oop_lab5/InFileRepository.h
        oop_lab5/InMemRepository.cpp
        oop_lab5/InMemRepository.h
        oop_lab5/main.cpp
        oop_lab5/Repository.h
        oop_lab5/test.cppT
        oop_lab5/UI.cpp
        oop_lab5/UI.h)
