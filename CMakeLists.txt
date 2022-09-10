cmake_minimum_required(VERSION 3.20)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(PROJECT_NAME "Haku-math")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message("Cmake C++ standard : ${CMAKE_CXX_STANDARD}")

add_subdirectory(include)
