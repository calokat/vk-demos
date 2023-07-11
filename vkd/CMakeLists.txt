cmake_minimum_required(VERSION 3.10)
file(GLOB VKD_SRC *.cc)
add_library(vkd STATIC ${VKD_SRC})
