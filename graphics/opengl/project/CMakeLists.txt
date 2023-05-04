cmake_minimum_requierd(VERSION 3.6)

set(ProjectName LearnOpenGL)

project(${LearnOpenGL})

# set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set module path
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# use build set
include(cmake/BuildSet.cmake)

# set src
aux_source_directory(src SOURCE_FILE)

# add main.cpp
list(APPEND SOURCE_FILE 
    main.cpp
    )

# add source file
add_executable(${ProjectName} ${SOURCE_FILE})

# add extra include
target_include_directories(${ProjectName}
    ${CMAKE_CURRENT_SOURCE_DIR}/extralInclude)

# use external library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external ${PROJECT_BINARY_DIR}/external)
target_link_libraries(${ProjectName} external)

# use all platform related libraries
use_libs_depend(${ProjectName})
