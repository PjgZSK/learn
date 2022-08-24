# cmake quick start
## 1. cmake language
* camke cache variables
    > cmake reserve identifiers that :  
    > * begin with `CMAKE_`(upper, lower or mixed-case), or  
    > * begin with `_CMAKE_`(upper, lower or mixed-case), or  
    > * begin with `_` followed by the name of any *Cmake_Command*

    > [ref](https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html#manual:cmake-variables(7))

## 2. cmake commands
* project
    > * `cmake_minimum_required`  
    > `cmake_minimum_required (VERSION 2.6)`  
    > * `project`  
    > `project (projectname)`
    > * `LINK_DIRECTORIES`  
    > `LINK_DIRECTORIES (path)`
* scripting
    > * `set`  
    > `set (variable values)`
    > * `foreach`  
    > ```
    > foreach (loop_var items)
    > commands ...
    > endforeach()
    > ```
