cmake_minimum_required(VERSION 3.5)
project(caffe.js.native)

set(NATIVE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CAFFE_BUILD}/lib -I${CAFFE_ROOT}/include -I${INCLUDE}")
include_directories(../../include "${CAFFE_ROOT}/include")

if ($ENV{CUDA_ROOT})
    set(CMAKE_CXX_COMPILER "${CUDA_ROOT}/bin/nvcc")
else ()
    message(STATUS "No CUDA found. Working in CPU mode.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCPU_ONLY")
endif ()

add_library(caffenative SHARED predict.cpp)
set_target_properties(caffenative PROPERTIES COMPILE_FLAGS ${NATIVE_CXX_FLAGS})
