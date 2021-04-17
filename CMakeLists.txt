cmake_minimum_required(VERSION 3.10)
project(alpha)

set(SOURCES main.cpp adc.cpp dcmotors.cpp)
set (CMAKE_CXX_FLAGS "-lwiringPi")

add_executable(${PROJECT_NAME} ${SOURCES})