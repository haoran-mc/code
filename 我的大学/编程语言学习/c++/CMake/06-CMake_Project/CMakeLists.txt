cmake_minimum_required(VERSION 3.0)

project(SOLDIERFIRE)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_executable(my_cmake_exe main.cpp src/Gun.cpp src/Soldier.cpp)
