cmake_minimum_required(VERSION 3.0)

project(SWAP)

# g++ main.cpp src/swap.cpp -Iinclude -o main
include_directories(include)

add_executable(main_cmake main.cpp src/swap.cpp)