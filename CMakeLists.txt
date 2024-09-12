cmake_minimum_required(VERSION 3.17)

set(LIB_NAME "Interact")
project(${LIB_NAME} CXX)

## Build static library

add_library(${LIB_NAME}
    src/Draggable.cpp include/Interact/Draggable.h
)
set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 20)
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${LIB_NAME} PRIVATE "include/Interact")

## sfml
target_link_libraries(${LIB_NAME} sfml-graphics sfml-window sfml-system)

