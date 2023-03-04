# CMakeLists.txt for opencv with c++
cmake_minimum_required(VERSION 3.0.0)
project(virtual_paint VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(virtual_paint projects/virtual_paint.cpp)

target_link_libraries(virtual_paint ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
