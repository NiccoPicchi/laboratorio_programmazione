cmake_minimum_required(VERSION 3.28)
project(laboratorio_programmazione)

set(CMAKE_CXX_STANDARD 11)

add_executable(laboratorio_programmazione main.cpp
        Note.cpp
        Note.h
        Notepad.cpp
        Notepad.h
        Subject.h
        Observer.h)
