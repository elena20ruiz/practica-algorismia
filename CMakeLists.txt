cmake_minimum_required(VERSION 3.9)
project(practica)

set(CMAKE_CXX_STANDARD 11)
include(CTest)
enable_testing()

add_executable(practica src/main.cpp src/classes/Network.cpp src/classes/Network.h src/problem/SolverBi.cpp src/problem/SolverBi.h src/algorithm/EKAlgoritm.h src/classes/Flight.cpp src/classes/Flight.h src/algorithm/EKAlgoritm.cpp src/problem/SolverCir.cpp src/problem/SolverCir.h)