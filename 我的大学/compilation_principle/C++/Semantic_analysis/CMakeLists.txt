cmake_minimum_required(VERSION 3.20)
project(Semantic_analysis)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(Semantic_analysis main.cpp src/WordAnalysis.cpp include/WordAnalysis.h src/OPGAnalysis.cpp include/OPGAnalysis.h src/OPGConstruct.cpp include/OPGConstruct.h src/Grammar.cpp include/Grammar.h)
