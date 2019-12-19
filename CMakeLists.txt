cmake_minimum_required(VERSION 3.15)
project(Cpp_Ex1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp_Ex1 main.cpp Matrix.cpp Activation.cpp Dense.cpp Dense.h MlpNetwork.cpp)