
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(traffic-light)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

find_package(OpenGL)
find_package(GLUT)

find_library(COCOA Cocoa)

include_directories(
    include
    ${GLUT_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
)

add_executable(
    traffic-light
    src/main.cpp
    src/circle.cpp
)

target_link_libraries(
    traffic-light
    ${COCOA_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)