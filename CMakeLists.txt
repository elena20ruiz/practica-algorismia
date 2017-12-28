cmake_minimum_required(VERSION 3.9)
project(practica)

set(CMAKE_CXX_STANDARD 11)

add_executable(practica main.cpp src/classes/Node.cpp src/classes/Node.h src/classes/Edge.cpp src/classes/Edge.h src/classes/Network.cpp src/classes/Network.h src/classes/Edge.cpp src/classes/Edge.h src/problem/Solver.cpp src/problem/Solver.h src/algorithm/EKAlgorithm.cpp src/algorithm/EKAlgoritm.cpp src/algorithm/EKAlgoritm.h)