cmake_minimum_required (VERSION 3.8)

project(shapelib_wrapper)

add_library(shapelib_wrapper STATIC)
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
    ${COMMON_INCLUDE_DIR}
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
    shapelib_wrapper.cpp
    shapelib_wrapper.h
    shp.cpp
    shp.h
 "dbf.h" "dbf.cpp")
