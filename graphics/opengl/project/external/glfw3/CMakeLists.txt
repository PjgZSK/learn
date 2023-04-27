cmake_minimum_required(3.6)

set(libname "glfw3")

include(../cmake/GLLearnExternalConfig.cmake)

add_library(${libname} SHARED IMPORTED GLOBAL)

set_target_properties(${libname} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/${platform_name}")

if(WINDOWS)
    set_target_properties(${libname} PROPERTIES
        IMPORTED_LOCATION "${platform_spec_path}/${libname}.lib")
elseif(MACOSX)
    set_target_properties(${libname} PROPERTIES
        IMPORTED_LOCATION "${platform_spec_path}/lib${libname}.a")
endif



