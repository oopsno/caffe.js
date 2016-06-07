cmake_minimum_required(VERSION 3.5)
project(caffe.js.node)

set(NODE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -I${CAFFE_INCLUDE} -I${INCLUDE}")
include_directories(${INCLUDE})

add_library(caffejs caffejs.cpp)
set_target_properties(caffejs PROPERTIES
        PREFIX ""
        SUFFIX ".node"
        COMPILE_FLAGS ${NODE_CXX_FLAGS})

target_include_directories(caffejs PRIVATE ${CMAKE_JS_INC})
target_link_libraries(caffejs ${CMAKE_JS_LIB})
