cmake_minimum_required(VERSION 3.20)
project(Syntax_analysis C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Syntax_analysis main.c src/Word_analyze.c src/Recursive_descent_analyze.c src/Forecast_analyze.c include/Word_analyze.h include/Recursive_descent_analyze.h include/Forecast_analyze.h)
