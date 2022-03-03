cmake_minimum_required(VERSION 3.7...3.22)
project(flightcheck)

set(CMAKE_CXX_STANDARD 20)

add_executable(flightcheck src/main.cpp src/CheckList.cpp src/CheckList.h src/CheckListTemplate.cpp src/CheckListTemplate.h src/Config.cpp src/Config.h)
