cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(server
    VERSION 1.0.0
    DESCRIPTION "ML Engineering CPP Project"
    LANGUAGES CXX
)

set(PREFIX_DIR vendor)
set(VENDOR_PACKAGES vendor)
include(ExternalProject)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/spdlog)
    ExternalProject_Add(
        spdlog
        GIT_REPOSITORY git@github.com:gabime/spdlog.git
        GIT_TAG v1.14.1
        PREFIX ${PREFIX_DIR}
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}
        BUILD_COMMAND cd ${CMAKE_BINARY_DIR}/${PREFIX_DIR}/src/spdlog-build && make -j
        TEST_COMMAND echo nothing to test...
    )
endif()

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/boost)
    ExternalProject_Add(
        boost
        URL https://archives.boost.io/release/1.85.0/source/boost_1_85_0.tar.gz
        PREFIX ${PREFIX_DIR}
        CONFIGURE_COMMAND cp -r ${CMAKE_BINARY_DIR}/${PREFIX_DIR}/src/boost/boost ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include
        BUILD_COMMAND echo nothing to build...
        INSTALL_COMMAND echo nothing to install...
        TEST_COMMAND echo nothing to test...
    )
endif()

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/oatpp)
    ExternalProject_Add(
        oatpp
        GIT_REPOSITORY git@github.com:oatpp/oatpp.git
        GIT_TAG 1.3.0-latest
        PREFIX ${PREFIX_DIR}
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}
        BUILD_COMMAND cd ${CMAKE_BINARY_DIR}/${PREFIX_DIR}/src/oatpp-build && make install
        TEST_COMMAND echo nothing to test...
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/oatpp-1.3.0/oatpp/oatpp ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/oatpp-1.3.0/oatpp/oatpp-test ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include
        COMMAND rm -rf ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/oatpp-1.3.0
    )
endif()

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/toml++)
    ExternalProject_Add(
        toml++
        GIT_REPOSITORY git@github.com:ToruNiina/toml11.git
        GIT_TAG v3.8.1
        PREFIX ${PREFIX_DIR}
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES} -DCMAKE_CXX_STANDARD=20
        TEST_COMMAND echo nothing to test...
        COMMAND mkdir ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/toml++
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/toml ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/toml++
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/toml.hpp ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_PACKAGES}/include/toml++
    )
endif()

# Define C++ source files
set(
    SOURCES
    ${CMAKE_SOURCE_DIR}/Main.cc
    ${CMAKE_SOURCE_DIR}/inbound/BaseRouter.cc
    ${CMAKE_SOURCE_DIR}/inbound/InfoRoute.cc
    ${CMAKE_SOURCE_DIR}/inbound/EchoRoute.cc
    ${CMAKE_SOURCE_DIR}/service/InfoService.cc
    ${CMAKE_SOURCE_DIR}/service/EchoService.cc
)

# Compilation of the C++ source files
add_executable(server ${SOURCES})

# Linking of custom project defined headers
target_include_directories(
    server PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/${VENDOR_PACKAGES}/include
)

target_link_libraries(
    server 
    ${CMAKE_SOURCE_DIR}/${VENDOR_PACKAGES}/lib/oatpp-1.3.0/liboatpp.a
)
