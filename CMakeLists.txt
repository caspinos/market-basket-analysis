cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")

if(CMAKE_COMPILER_IS_GNUCXX)
    list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
endif()

find_package(sqlite3 REQUIRED)
include_directories(${SQLITE_INCLUDE_DIR})


project(program)
add_executable(program main.cpp libsqlite.hpp market_analysis_tools.h market_analysis_tools.cpp Application.h Application.cpp)
target_link_libraries(program ${SQLITE_LIBRARY})