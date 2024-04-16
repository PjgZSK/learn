cmake_minimum_required(VERSION 3.6)

set(ProjectName "external")

add_library(${ProjectName} empty.cpp)

if (WIN32)
     target_link_libraries(${ProjectName} ${CMAKE_CURRENT_SOURCE_DIR}/glfw3/prebuild/win32/glfw3.lib)
elseif(APPLE)
     target_link_libraries(${ProjectName} ${CMAKE_CURRENT_SOURCE_DIR}/glfw3/prebuild/mac/libglfw3.a)
endif()