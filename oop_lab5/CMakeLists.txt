cmake_minimum_required(VERSION 3.21)
project(oop_lab5)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop_lab5 main.cpp Domain.cpp Domain.h Repository.h Controller.cpp Controller.h UI.cpp UI.h test.cppT InMemRepository.cpp InMemRepository.h InFileRepository.cpp InFileRepository.h)
