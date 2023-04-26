cmake_minimum_required(3.6)

set(libname "glfw3")

add_library(${libname} SHARED IMPORTED GLOBAL)

set_target_properties(${libname} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include/${platform_name})
