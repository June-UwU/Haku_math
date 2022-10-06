cmake_minimum_required(VERSION 3.20)



set(PROJECTNAME haku_math)
set(PROJECTDIR "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE inc "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE inl "${CMAKE_CURRENT_SOURCE_DIR}/*.inl")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${inc})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${inl})

if (MSVC)
  add_compile_options(/W3) # warning level 3
  add_compile_options(/MP) # Multi-processor compilation
endif()

add_library(
  ${PROJECTNAME}
  INTERFACE
  ${inc}
  ${inl}
  )


target_include_directories(${PROJECTNAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)

