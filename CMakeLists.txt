cmake_minimum_required(VERSION 3.17)

set(LIB_NAME "Interact")
project(${LIB_NAME} CXX)

add_library(${LIB_NAME}
    include/Interact/Drag.h src/Drag.cpp
    include/Interact/Shape.h src/Shape.cpp
    include/Interact/Interaction.h
    include/Interact/Hover.h src/Hover.cpp
    include/Interact/ArrowShape.h src/ArrowShape.cpp
)
set_target_properties(${LIB_NAME} PROPERTIES CXX_STANDARD 20 LINKER_LANGUAGE CXX)

target_include_directories(${LIB_NAME} PRIVATE "include/Interact")

## sfml
target_link_libraries(${LIB_NAME} sfml-graphics sfml-window sfml-system)
