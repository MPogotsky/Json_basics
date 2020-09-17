cmake_minimum_required(VERSION 3.17)
project(Json_basics)

set(CMAKE_CXX_STANDARD 14)

include_directories("/usr/include/rapidjson")

add_executable(Json_basics main.cpp JsonManager.cpp JsonManager.h)