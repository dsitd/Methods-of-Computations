cmake_minimum_required(VERSION 3.24)
project(Methods_of_Computation)

set(CMAKE_CXX_STANDARD 17)

add_executable(Methods_of_Computation main.cpp src/equation.h src/interval.h src/algorithm/algorithm.h src/algorithm/methods/BisectionMethod.cpp src/algorithm/methods/BisectionMethod.h src/algorithm/methods/NewtonMethod.cpp src/algorithm/methods/NewtonMethod.h src/algorithm/methods/ModifiedNewtonMethod.cpp src/algorithm/methods/ModifiedNewtonMethod.h src/algorithm/methods/SecantMethod.cpp src/algorithm/methods/SecantMethod.h)
