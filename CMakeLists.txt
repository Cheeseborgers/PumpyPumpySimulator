cmake_minimum_required(VERSION 3.16)
project(PumpyPumpySimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(PumpyPumpySimulator main.cpp Game.cpp Game.h)

add_subdirectory(include/SFML)

target_link_libraries(
        PumpyPumpySimulator
        PUBLIC
        sfml-graphics sfml-window sfml-system
)

target_include_directories(PumpyPumpySimulator PRIVATE)