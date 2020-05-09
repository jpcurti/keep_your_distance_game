cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17) 

set(CXX_FLAGS "-Wall" )
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(KeepYourDistance src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/GameObject.cpp src/Player.cpp src/Person.cpp src/Item.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(KeepYourDistance ${SDL2_LIBRARIES})
