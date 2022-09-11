cmake_minimum_required(VERSION 3.20)

set(PROJECTNAME haku-mathematics)
set(PROJECTDIR "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE inc "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB_RECURSE inl "${CMAKE_CURRENT_SOURCE_DIR}/*.inl")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${inc})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${inl})

add_library(
	${PROJECTNAME}
	INTERFACE
	${inc}
	${inl}
	)


