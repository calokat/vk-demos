cmake_minimum_required(VERSION 3.10)
project(vkDemos)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Vulkan REQUIRED COMPONENTS glslc)
add_subdirectory(third-party)
add_subdirectory(vkd)
add_subdirectory(basic-lighting)
find_program(glslc_executable NAMES glslc HINTS Vulkan::glslc)
