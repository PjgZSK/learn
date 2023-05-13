cmake_minimum_required(VERSION 3.17)

set(ProjectName LearnOpenGL)

project(${ProjectName})

# set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set module path
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# use build set
include(cmake/BuildSet.cmake)

# set src
#aux_source_directory(src SOURCE_FILE)
file(GLOB_RECURSE SOURCE_FILE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp" "src/*.c")

# set head
file(GLOB_RECURSE HEAD_FILE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h" "src/*.hpp")

# add main.cpp
list(APPEND SOURCE_FILE 
    main.cpp
    )

# add resource
set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/resource"
    )
set(GAME_SHADER_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/shader"
    )
file(GLOB_RECURSE SHADER_FILE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "shader/*")
file(GLOB_RECURSE RESOURCE_FILE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "resource/*")

# log source file, head file resource file and shader file
message(STATUS "SOURCE FILE: " ${SOURCE_FILE})
message(STATUS "HEAD FILE: " ${HEAD_FILE})
message(STATUS "RESOURCE FILE: " ${RESOURCE_FILE})
message(STATUS "SHADER FILE: " ${SHADER_FILE})

# add source file
add_executable(${ProjectName} ${SOURCE_FILE} ${HEAD_FILE} ${RESOURCE_FILE} ${SHADER_FILE})

# set work directory
set_target_properties(${ProjectName} PROPERTIES 
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    XCODE_GENERATE_SCHEME TRUE
    XCODE_SCHEME_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

# apple mark resource
if(APPLE)
    set_target_properties(${ProjectName} PROPERTIES
        RESOURCE "${RESOURCE_FILES}")
endif()

# add source group
set(ALL_SOURCE_FILE ${SOURCE_FILE} ${HEAD_FILE} ${SHADER_FILE})
foreach(source ${ALL_SOURCE_FILE})
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

# add extra include
target_include_directories(${ProjectName} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extralInclude)

# add current dir
target_include_directories(${ProjectName} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

# use external library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external ${PROJECT_BINARY_DIR}/external)
target_link_libraries(${ProjectName} external)

# use all platform related libraries
use_libs_depend(${ProjectName})

# set ide properties
if(APPLE)
    # output macOS/iOS .app
    set_target_properties(${ProjectName} PROPERTIES MACOSX_BUNDLE 1)
elseif(MSVC)
    # visual studio default is Console app, but we need Windows app
    set_property(TARGET ${ProjectName} APPEND PROPERTY LINK_FLAGS "/SUBSYSTEM:WINDOWS")
endif()
