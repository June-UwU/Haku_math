cmake_minimum_required (VERSION 3.20)

project(haku_math
  VERSION ${DIRECTXMATH_VERSION}
  DESCRIPTION "Haku SIMD C math library"
  LANGUAGES C)


#--- Library
set(LIBRARY_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/haku_math.hpp
    )


add_subdirectory("include/")
add_subdirectory("tests/")