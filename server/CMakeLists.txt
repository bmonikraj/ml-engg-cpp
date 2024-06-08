cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(server
    VERSION 1.0.0
    DESCRIPTION "ML Engineering CPP Project"
    LANGUAGES CXX
)

set(PREFIX_DIR vendor)
set(VENDOR_PACKAGES_INCLUDE vendor)
include(ExternalProject)

ExternalProject_Add(
    spdlog
    GIT_REPOSITORY git@github.com:gabime/spdlog.git
    GIT_TAG v1.14.1
    PREFIX ${PREFIX_DIR}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES_INCLUDE}
    BUILD_COMMAND cd ${CMAKE_BINARY_DIR}/${PREFIX_DIR}/src/spdlog-build && make -j
)

# Define C++ source files
set(
    SOURCES
    ${CMAKE_SOURCE_DIR}/Main.cc
    ${CMAKE_SOURCE_DIR}/service/Circle.cc
    ${CMAKE_SOURCE_DIR}/service/Square.cc
)

# Compilation of the C++ source files
add_executable(server ${SOURCES})

# Linking of custom project defined headers
target_include_directories(
    server PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/${VENDOR_PACKAGES_INCLUDE}/include
)
