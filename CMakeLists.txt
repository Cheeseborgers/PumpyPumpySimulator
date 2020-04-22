cmake_minimum_required(VERSION 3.16)
project(PumpyPumpySimulator
        VERSION 0.0.1
        DESCRIPTION "Some dumb game"
        )

set(CMAKE_CXX_STANDARD 20)

add_executable(PumpyPumpySimulator
        main.cpp
        Game.cpp Game.h
        Player.cpp Player.h
        Pump.cpp Pump.h
        states/State.cpp states/State.h
        states/MainMenuState.cpp states/MainMenuState.h
        states/IntroState.cpp states/IntroState.h)

add_subdirectory(include/SFML)

target_link_libraries(
        PumpyPumpySimulator
        PUBLIC
        sfml-graphics sfml-window sfml-system
)

target_include_directories(PumpyPumpySimulator PRIVATE)