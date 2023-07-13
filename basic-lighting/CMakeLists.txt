cmake_minimum_required(VERSION 3.10)
add_executable(BasicLighting main.cc)
file(GLOB SHADERS shaders/*)

target_include_directories(BasicLighting PUBLIC ${CMAKE_SOURCE_DIR}/include/ ${CMAKE_SOURCE_DIR} ${Vulkan_INCLUDE_DIRS})

add_custom_command(TARGET BasicLighting PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:BasicLighting>/shaders/)

foreach(shader IN LISTS SHADERS)
    get_filename_component(shader_name_we ${shader} NAME_WE)
    get_filename_component(shader_name ${shader} NAME)
    get_filename_component(shader_ext ${shader} EXT)
    message(STATUS "Compiling ${shader_name_we}")
    add_custom_target(compile_shader_${shader_name} ALL glslc ${shader} -o $<TARGET_FILE_DIR:BasicLighting>/shaders/${shader_name}.spv)
endforeach()

target_link_libraries(BasicLighting Vulkan::Vulkan glfw glm imgui vkd)
add_custom_command(TARGET BasicLighting POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/basic-lighting/models/ $<TARGET_FILE_DIR:BasicLighting>/models/)
add_custom_command(TARGET BasicLighting POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/basic-lighting/textures/ $<TARGET_FILE_DIR:BasicLighting>/textures/)
