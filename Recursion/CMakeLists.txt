cmake_minimum_required(VERSION 3.15)
project(Recursion VERSION 1.0)

add_library(tutorial_compiler_flags INTERFACE)
add_library(RecursiveFunctions recursive.cpp)

target_include_directories(RecursiveFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(RecursiveFunctions tutorial_compiler_flags)

target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-g>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

add_executable(Recursion main.cpp)

target_link_libraries(Recursion PUBLIC RecursiveFunctions)
target_include_directories(Recursion PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )