cmake_minimum_required(3.6)

include(cmake/GLLearnExternalConfig.cmake)

set(libname "external")

add_library(${libname} empty.cpp)

if(WINDOWS | MACOSX)
    add_subdirectory(glfw3)
    target_link_libraries(${libname}
        ext_glfw3)
endif

