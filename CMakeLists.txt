cmake_minimum_required(VERSION 3.17)
project(hufftree)

set(CMAKE_CXX_STANDARD 14)

add_executable(hufftree main.cpp hufftree.cpp queue.cpp node.h hufftree.h queue.h)