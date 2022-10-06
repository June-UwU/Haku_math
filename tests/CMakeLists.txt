cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "tests")


file(GLOB_RECURSE global_src ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

project(${PROJECT_NAME})


if (MSVC)
    add_compile_options(/W3) # warning level 3
	add_compile_options(/MP) # Multi-processor compilation
	add_compile_options(/fp:fast) # Fast FP
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
		${PROJECT_NAME}
		${global_src})


target_link_libraries(${PROJECTNAME} haku_math)
add_test(NAME UnitTest COMMAND ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#gtest requires cxx with a minimum of cxx14 standard
target_compile_features(${PROJECT_NAME} INTERFACE CXX_STANDARD_20)




target_link_libraries(
  ${PROJECT_NAME}
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

