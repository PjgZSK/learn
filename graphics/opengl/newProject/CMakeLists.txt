cmake_minimum_required(VERSION 3.8)

set(ProjectName LearnOpenGL)
project(${ProjectName})

# add executable
file(GLOB_RECURSE SourceFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HeadFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.hpp" "*.h")
add_executable(${ProjectName} ${SourceFiles} main.cpp ${HeadFiles})

# include search path
target_include_directories(${ProjectName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${ProjectName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/extralInclude)
target_include_directories(${ProjectName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external)

# add external lib
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external ${PROJECT_BINARY_DIR}/external)
target_link_libraries(${ProjectName} external)

# add system lib
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(cmake/AddSystemLib.cmake)
add_system_depends(${ProjectName})

# ide
if(APPLE)
    set_target_properties(${ProjectName} PROPERTIES MACOSX_BUNDLE 1)
elseif(MSVC)
    set_property(TARGET ${ProjectName} APPEND PROPERTY LINK_FLAGS "/SUBSYSTEM:WINDOWS")
    set_property(TARGET ${ProjectName} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()