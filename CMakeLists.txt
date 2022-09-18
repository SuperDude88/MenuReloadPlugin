cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("./PluginSystem.cmake" REQUIRED)

project(reloadplugin CXX)
add_compile_options(-Ofast -Wall)

add_executable(reloadplugin main.cpp)
wups_create_plugin(reloadplugin)
