cmake_minimum_required(VERSION 3.13)
project(pipeline_graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(../eigen)


add_executable(pipeline_graph ./src/node.cpp ./src/edge.cpp ./test/node_edge_test.cpp)