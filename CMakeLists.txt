cmake_minimum_required(VERSION 3.9)
project(practica)

set(CMAKE_CXX_STANDARD 11)

add_executable(practica src/algorithm/EKAlgoritm.cpp src/algorithm/EKAlgoritm.h
                        src/classes/Edge.cpp  src/classes/Edge.h src/classes/Node.cpp src/classes/Node.h
                        src/classes/Network.cpp src/classes/Network.h
                        src/problem/Solver.cpp src/problem/Solver.h src/main.cpp)