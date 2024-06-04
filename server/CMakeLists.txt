cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(server
    VERSION 1.0.0
    DESCRIPTION "ML Engineering CPP Project"
    LANGUAGES CXX)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/Main.cc
    ${CMAKE_SOURCE_DIR}/service/Circle.cc
    ${CMAKE_SOURCE_DIR}/service/Square.cc
)

add_executable(server ${SOURCES})
