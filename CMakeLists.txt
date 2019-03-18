cmake_minimum_required(VERSION 3.13)
project(pipeline_graph)

set(CMAKE_CXX_STANDARD 14)
# CMake Modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# Boost Archive
find_package(Boost REQUIRED COMPONENTS system serialization)
include_directories(${BOOST_INCLUDE_DIRS})
link_libraries(${Boost_SERIALIZATION_LIBRARY} ${Boost_SYSTEM_LIBRARY})


# Include directories
include_directories(${pipeline_graph_SOURCE_DIR}/include
        ${pipeline_graph_SOURCE_DIR}/src
        ${pipeline_graph_SOURCE_DIR}/test
        ${pipeline_graph_SOURCE_DIR}/cmake
        ${pipeline_graph_SOURCE_DIR}/external)

add_executable(pipeline_graph
        ${pipeline_graph_SOURCE_DIR}/src/edge.cc
        ${pipeline_graph_SOURCE_DIR}/src/node.cc
        ${pipeline_graph_SOURCE_DIR}/src/mesh.cc
#        ./test/node_edge_test.cc
        ${pipeline_graph_SOURCE_DIR}/test/mesh_test.cc)