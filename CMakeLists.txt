cmake_minimum_required(VERSION 3.15)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(BattleShip
        src/2020HW6.cpp
        src/Battleship.cpp
        src/Battleship.h
        src/Board.cpp
        src/Board.h
        src/Carrier.cpp
        src/Carrier.h
        src/Coordinate.cpp
        src/Coordinate.h
        src/Cruiser.cpp
        src/Cruiser.h
        src/Destroyer.cpp
        src/Destroyer.h
        src/Production.cpp
        src/Production.h
        src/Screen.cpp
        src/Screen.h
        src/Ship.cpp
        src/Ship.h
        src/Stats.cpp
        src/Stats.h
        src/Submarine.cpp
        src/Submarine.h
        src/Tests.cpp
        src/Tests.h)
