cmake_minimum_required(VERSION 3.10)
project(samochodzik)

set(SOURCES main.cpp adc.cpp dcmotors.cpp buzzer.cpp phres.cpp servo.cpp sonar.cpp hall.cpp)
set (CMAKE_CXX_FLAGS "-lwiringPi")

add_executable(${PROJECT_NAME} ${SOURCES})