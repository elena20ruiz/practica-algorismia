cmake_minimum_required(VERSION 3.9)
project(practica_algorismia)

set(CMAKE_CXX_STANDARD 11)

add_executable(practica_algorismia src/classes/Transition.cpp src/classes/Transition.h src/Main.cpp src/classes/Problem.cpp src/classes/Problem.h src/classes/Pilot.cpp src/classes/Pilot.h src/control/Solver.cpp src/control/Solver.h)