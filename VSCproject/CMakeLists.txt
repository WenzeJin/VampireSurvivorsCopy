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

add_executable(VSCproject main.cpp)
target_link_libraries(VSCproject
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

