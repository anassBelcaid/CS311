cmake_minimum_required(VERSION 3.7)
project(containers)

# compiler requisites
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt requisites
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)



add_executable(vectors vectors.cpp )
target_link_libraries(vectors Qt5::Widgets)

add_executable(list lists.cpp )
target_link_libraries(list Qt5::Widgets)
