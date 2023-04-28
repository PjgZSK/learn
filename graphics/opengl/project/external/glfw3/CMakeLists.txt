cmake_minimum_required(3.6)

set(lib_name "glfw3")
set(target_name ext_${lib_name})

include(../cmake/GLLearnExternalConfig.cmake)

add_library(${target_name} SHARED IMPORTED GLOBAL)

set_target_properties(${lib_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/${platform_name}")

if(WINDOWS)
    set_target_properties(${lib_name} PROPERTIES
        IMPORTED_LOCATION "${platform_spec_path}/${lib_name}.lib")
elseif(MACOSX)
    set_target_properties(${lib_name} PROPERTIES
        IMPORTED_LOCATION "${platform_spec_path}/lib${lib_name}.a")
endif



