# Example files of CMake
## copy files and folders files
1. source : cocos2d/cmake/Modules/CocosBuildHelper.cmake  
2. code  
```
include(CMakeParseArguments)

# copy resource `FILES` and `FOLDERS` to TARGET_FILE_DIR/Resources
function(cocos_copy_target_res cocos_target)
    set(oneValueArgs COPY_TO)
    set(multiValueArgs FILES FOLDERS)
    cmake_parse_arguments(opt "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    add_custom_command(TARGET ${cocos_target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "copying resources..."
    )    
    # copy files
    foreach(cc_file ${opt_FILES})
        get_filename_component(file_name ${cc_file} NAME)
        add_custom_command(TARGET ${cocos_target} POST_BUILD
            #COMMAND ${CMAKE_COMMAND} -E echo "copy file into Resources: ${file_name} ..."
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${cc_file} "${opt_COPY_TO}/${file_name}"
        )
    endforeach()
    # copy folders files
    foreach(cc_folder ${opt_FOLDERS})
        file(GLOB_RECURSE folder_files "${cc_folder}/*")
        get_filename_component(folder_abs_path ${cc_folder} ABSOLUTE)
        foreach(res_file ${folder_files})
            get_filename_component(res_file_abs_path ${res_file} ABSOLUTE)
            file(RELATIVE_PATH res_file_relat_path ${folder_abs_path} ${res_file_abs_path})
            add_custom_command(TARGET ${cocos_target} POST_BUILD
                #COMMAND ${CMAKE_COMMAND} -E echo "copy file into Resources: ${res_file_relat_path} ..."
                COMMAND ${CMAKE_COMMAND} -E copy_if_different ${res_file} "${opt_COPY_TO}/${res_file_relat_path}"
            )
        endforeach()
    endforeach()
endfunction()
```
3. Commands :  
    * include  
    * function  
    * set  
    * cmake_parse_arguments  
    * add_custom_command  
    * foreach  
    * get_filename_component  
    * file    

## Get all linked libraries including transitive ones, recursive
1. source : cocos2d/cmake/Modules/CocosBuildHelper.cmake   
2. code  
```
# get all linked libraries including transitive ones, recursive
function(search_depend_libs_recursive cocos_target all_depends_out)
    set(all_depends_inner)
    set(targets_prepare_search ${cocos_target})
    while(true)
        foreach(tmp_target ${targets_prepare_search})
            get_target_property(target_type ${tmp_target} TYPE)
            if(${target_type} STREQUAL "SHARED_LIBRARY" OR ${target_type} STREQUAL "STATIC_LIBRARY" OR ${target_type} STREQUAL "MODULE_LIBRARY" OR ${target_type} STREQUAL "EXECUTABLE")
                #interface-only libraries do not support certain properties such as LINK_LIBRARIES
                get_target_property(tmp_depend_libs ${tmp_target} LINK_LIBRARIES)
                list(REMOVE_ITEM targets_prepare_search ${tmp_target})
                list(APPEND tmp_depend_libs ${tmp_target})
                foreach(depend_lib ${tmp_depend_libs})
                    if(TARGET ${depend_lib})
                        list(APPEND all_depends_inner ${depend_lib})
                        if(NOT (depend_lib STREQUAL tmp_target))
                            list(APPEND targets_prepare_search ${depend_lib})
                        endif()
                    endif()
                endforeach()
            else()
                list(REMOVE_ITEM targets_prepare_search ${tmp_target})
            endif()
        endforeach()
        list(LENGTH targets_prepare_search targets_prepare_search_size)
        if(targets_prepare_search_size LESS 1)
            break()
        endif()
    endwhile(true)
    set(${all_depends_out} ${all_depends_inner} PARENT_SCOPE)
endfunction()
```
3. Commands  
    * get_target_property  
    * if  
    * list  

## cocos2dx project top level CMakeLists
1. code  
```
cmake_minimum_required(VERSION 3.6)

set(APP_NAME BubbleShooter)

project(${APP_NAME})

set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

# record sources, headers, resources...
FILE(GLOB ALL_INCLUDES
	"Classes/*.*"
	"Classes/*/*.*"
	"Classes/*/*/*.*"
	"Classes/*/*/*/*.*"
	"Classes/*/*/*/*/*.*"
	"Classes/*/*/*/*/*/*.*"
)
set(GAME_HEADER ${ALL_INCLUDES})


aux_source_directory(Classes GAME_SOURCE)
```
2. commands  
