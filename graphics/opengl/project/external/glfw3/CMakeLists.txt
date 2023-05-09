cmake_minimum_required(VERSION 3.6)

set(lib_name "glfw3")
set(target_name ext_${lib_name})

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/GLLearnExternalConfig.cmake)

add_library(${target_name} STATIC IMPORTED GLOBAL)

set_target_properties(${target_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/${platform_name}")

message(STATUS "platform_spec_path:" ${platform_spec_path})
if(WINDOWS)
    set_target_properties(${target_name} PROPERTIES
        IMPORTED_LOCATION "${platform_spec_path}/${lib_name}.lib")
    message(STATUS "windows::platform_spec_path:${platform_spec_path}/${lib_name}.lib")
elseif(MACOSX)
    set_target_properties(${target_name} PROPERTIES
        IMPORTED_LOCATION "${platform_spec_path}/lib${lib_name}.a")
    message(STATUS "macosx::platform_spec_path:${platform_spec_path}/${lib_name}.lib")
endif()



