cmake_minimum_required(VERSION 3.5)
project(caffe.js)

set(CAFFE_ROOT $ENV{CAFFE_ROOT})
set(CAFFE_INCLUDE "${CAFFE_ROOT}/include")
set(CAFFE_CMAKE "${CAFFE_ROOT}/cmake")
set(CUDA_ROOT $ENV{CUDA_ROOT})
set(INCLUDE "${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src/native)
add_subdirectory(src/node)

