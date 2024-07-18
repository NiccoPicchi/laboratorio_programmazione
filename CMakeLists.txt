cmake_minimum_required(VERSION 3.28)
project(laboratorio_programmazione)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES Note.cpp Note.h Notepad.h Notepad.cpp NotepadObserver.h NotepadObserver.cpp)

add_executable(laboratorio_programmazione main.cpp
        Note.cpp
        Note.h
        Notepad.cpp
        Notepad.h
        Subject.h
        Observer.h
        NotepadObserver.cpp
        NotepadObserver.h)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)