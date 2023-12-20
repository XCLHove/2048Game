cmake_minimum_required(VERSION 3.26)
project(2048Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt6/6.3.2/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(2048Game main.cpp
        gameboard/gameboard.cpp
        gameboard/gameboard.h
        cell/cell.cpp
        cell/cell.h
        game/game.cpp
        game/game.h)
target_link_libraries(2048Game
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

