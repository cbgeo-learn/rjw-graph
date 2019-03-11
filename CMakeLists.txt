cmake_minimum_required(VERSION 3.13)
project(pipeline_graph)

set(CMAKE_CXX_STANDARD 14)
# CMake Modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# Include directories
include_directories(./include
        ./src
        ./test
        ./cmake
        ./external)

add_executable(pipeline_graph
        ./src/edge.cc
        ./src/node.cc
        ./src/mesh.cc
#        ./test/node_edge_test.cc
        ./test/mesh_test.cc)