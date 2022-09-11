cmake_minimum_required(VERSION 3.20)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(PROJECT_NAME "Haku-math")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message("Cmake C++ standard : ${CMAKE_CXX_STANDARD}")

add_library(sse4_1 INTERFACE IMPORTED)
if (MSVC)
    add_compile_options(/W3) # warning level 3
	add_compile_options(/MP) # Multi-processor compilation
    target_compile_options(sse4_1 INTERFACE /arch:SSE4.1)

else()
	target_compile_options(sse4_1 INTERFACE -msse4.1)

endif()


add_subdirectory(include)
