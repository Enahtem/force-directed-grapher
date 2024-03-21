# Requirements
cmake_minimum_required(VERSION 3.22)

# Project Name and Properties
set(PROJECT_NAME "Project-Eidos")
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

# Main Source Code Location, Adding as Executable
set(SOURCES "main.cc")
add_executable(${PROJECT_NAME} ${SOURCES})


# DON'T KNOW WHAT THIS IS, NOT NECESSARY?
# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
# find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)


# Library Names (folder names as well). Can add more.
set(LIBRARY_NAMES "graph")

# Adding Library Subdirectory
add_subdirectory("src")

#Linking SFML+Its Requirements and local libraries
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system pthread ${LIBRARY_NAMES})

#Sets Coding Language to C++ 17
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
