cmake_minimum_required(VERSION 3.5)
project(caffe_js)

set(CAFFE_ROOT "/home/liuyufei/caffe-git")
set(CAFFE_BUILD "${CAFFE_ROOT}/build")

if(NOT APPLE)
set(CMAKE_CXX_COMPILER /usr/local/cuda/bin/nvcc)
endif(NOT APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -L${CAFFE_BUILD}/lib")

set(SOURCE_FILES predict.cpp)
include_directories(include "${CAFFE_ROOT}/include")
add_executable(predict ${SOURCE_FILES})
target_link_libraries(det protobuf opencv_core opencv_highgui opencv_imgproc caffe glog boost_system)
