cmake_minimum_required(VERSION 3.15)
project(Arrays VERSION 1.0)

add_library(tutorial_compiler_flags INTERFACE)
add_library(ArraysLib array.cpp)

target_include_directories(ArraysLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ArraysLib tutorial_compiler_flags)

target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
set(CMAKE_BUILD_TYPE Debug)
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-g>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

add_executable(Arrays main.cpp)

target_link_libraries(Arrays PUBLIC ArraysLib)
target_include_directories(Arrays PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )