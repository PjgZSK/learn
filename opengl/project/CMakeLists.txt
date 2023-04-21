cmake_minimum_requierd(VERSION 3.6)

set(ProjectName LearnOpenGL)

project(${LearnOpenGL})

# set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
    PRIVATE openglthirdparty/Include
    )

# link extra library
target_link_libraries(${ProjectName} 
