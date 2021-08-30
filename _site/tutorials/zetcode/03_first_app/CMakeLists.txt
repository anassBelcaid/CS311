cmake_minimum_required(VERSION 3.7)
project(firstApp)

# compiler requisites
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt requisites
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)



add_executable( firstApp application.cpp )

target_link_libraries( firstApp Qt5::Widgets)

