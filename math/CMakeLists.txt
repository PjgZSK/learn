cmake_minimum_required(VERSION 3.10)

project(All VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

aux_source_directory(./ Sources)

add_executable(All ${Sources})
