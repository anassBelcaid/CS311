cmake_minimum_required(VERSION 3.7)
project(strings)

# compiler requisites
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt requisites
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)



add_executable(append_prepend 01_append_prepend.cpp)
target_link_libraries(append_prepend Qt5::Widgets)


add_executable(build_strings 02_build_string.cpp)
target_link_libraries(build_strings Qt5::Widgets)


add_executable(splitting 03_split_string.cpp)
target_link_libraries(splitting Qt5::Widgets)
