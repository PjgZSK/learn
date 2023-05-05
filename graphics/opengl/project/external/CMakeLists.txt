cmake_minimum_required(VERSION 3.6)

# set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/GLLearnExternalConfig.cmake)

set(libname "external")

add_library(${libname} empty.cpp)

if(WINDOWS OR MACOSX)
    add_subdirectory(glfw3)
    target_link_libraries(${libname}
        ext_glfw3)
endif()

