cmake_minimum_required(VERSION 3.6)

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
aux_source_directory(src SOURCE_FILE)

# set header
file(GLOB_RECURSE HEADER_FILE "src/*.h" "src/*.hpp")

# add main.cpp
list(APPEND SOURCE_FILE 
    main.cpp
    )

# add source file
add_executable(${ProjectName} ${SOURCE_FILE} ${HEADER_FILE})

# add extra include
target_include_directories(${ProjectName} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extralInclude)

# use external library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external ${PROJECT_BINARY_DIR}/external)
target_link_libraries(${ProjectName} external)

# use all platform related libraries
use_libs_depend(${ProjectName})

# add resource
set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/resource"
    )
if(APPLE)
    set(RESOURCE_FILES)
    file(GLOB_RECURSE folder_files "${GAME_RES_FOLDER}/*")
    foreach(res_file ${folder_files})
        list(APPEND RESOURCE_FILES
            ${res_file}
            )
    endforeach()
   set_target_properties(${ProjectName} PROPERTIES
        RESOURCE ${RESOURCE_FILES})
endif()

if(LINUX OR WINDOWS)
    set(APP_RES_DIR ${CMAKE_CURRENT_BINARY_DIR}/resource)
    copy_target_res(${ProjectName} COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()

if(APPLE)
    # output macOS/iOS .app
    set_target_properties(${ProjectName} PROPERTIES MACOSX_BUNDLE 1)
elseif(MSVC)
    # visual studio default is Console app, but we need Windows app
    set_property(TARGET ${ProjectName} APPEND PROPERTY LINK_FLAGS "/SUBSYSTEM:WINDOWS")
 endif()
