# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)

project ("shapelib_wrapper")
set(CMAKE_CXX_STANDARD 11)

# サブプロジェクトを含めます。
include("3rdparty/shapelib.cmake")

set (COMMON_INCLUDE_DIR
    ${SHAPELIB_INCLUDE_DIR}
)

add_subdirectory ("shapelib_wrapper")
