cmake_minimum_required (VERSION 3.8)

set(SHAPELIB_BUILD_DIR ${CMAKE_BINARY_DIR}/3rdpaty/shapelib)

include(ExternalProject)
ExternalProject_Add(
    shapelib
    PREFIX ${SHAPELIB_BUILD_DIR}
    GIT_REPOSITORY https://github.com/OSGeo/shapelib.git
    GIT_TAG v1.5.0
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)

ExternalProject_Get_Property(shapelib SOURCE_DIR)
set(SHAPELIB_INCLUDE_DIR ${SOURCE_DIR})
message(STATUS shapelib SOURCE_DIR = ${SHAPELIB_INCLUDE_DIR})
