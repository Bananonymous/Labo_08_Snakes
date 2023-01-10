cmake_minimum_required(VERSION 3.24)
project(Labo_08_Snakes)

set(CMAKE_CXX_STANDARD 20)

set(SDL2_PATH "C:/Users/Athena/Downloads/SDL2-devel-2.26.2-mingw/SDL2-2.26.2")
find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )

add_executable(Labo_08_Snakes main.cpp)

target_link_libraries(Labo_08_Snakes ${SDL2_LIBRARY} )