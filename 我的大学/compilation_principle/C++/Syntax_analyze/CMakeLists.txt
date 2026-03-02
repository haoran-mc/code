cmake_minimum_required(VERSION 3.20)
project(Syntax_analyze)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Syntax_analyze main.cpp src/WordAnalysis.cpp include/WordAnalysis.h src/RecursiveDescentAnalysis.cpp include/RecursiveDescentAnalysis.h src/ForecastAnalysis.cpp include/ForecastAnalysis.h)
