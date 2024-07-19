cmake_minimum_required(VERSION 3.5)
project(laboratorio_programmazione)
set(CXX_STANDARD 11)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp NotepadTest.cpp)
add_executable(runNotepadTests ${TEST_SOURCE_FILES})
target_link_libraries(runNotepadTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)