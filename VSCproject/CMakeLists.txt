cmake_minimum_required(VERSION 3.25)
project(VSCproject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Applications/Qt/6.4.1/macos")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(VSCproject gameres.qrc main.cpp gamemain.cpp gamemain.h gamemain.ui menu.cpp menu.h menu.ui GameLogic/GameState.cpp GameLogic/GameState.h GameLogic/config.h GameLogic/PaintInfo.cpp GameLogic/PaintInfo.h GameLogic/GameMap.cpp GameLogic/GameMap.h GameLogic/Hero.cpp GameLogic/Hero.h GameLogic/Option.cpp GameLogic/Option.h GameLogic/Weapon.cpp GameLogic/Weapon.h)
target_link_libraries(VSCproject
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

