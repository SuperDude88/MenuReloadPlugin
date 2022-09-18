cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("./PluginSystem.cmake" REQUIRED)

project(menureload CXX)
add_compile_options(-Ofast -Wall)

add_executable(menureload main.cpp)
wups_create_plugin(menureload)
