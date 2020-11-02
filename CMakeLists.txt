cmake_minimum_required(VERSION 3.17)
project(Project4_HighestPriority)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project4_HighestPriority p3.cpp Patient.cpp Patient.h PatientPriorityQueue.cpp PatientPriorityQueue.h)