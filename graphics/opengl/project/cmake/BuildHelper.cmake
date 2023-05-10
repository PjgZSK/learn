# copy resource `FILES` and `FOLDERS` to TARGET_FILE_DIR/Resources
function(copy_target_res target)
    set(oneValueArgs COPY_TO)
    set(multiValueArgs FILES FOLDERS)
    cmake_parse_arguments(opt "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # copy files
    foreach(cc_file ${opt_FILES})
        get_filename_component(file_name ${cc_file} NAME)
        file(COPY_FILE ${cc_file} DESTINATION "${opt_COPY_TO}/${file_name}")
    endforeach()
    # copy folders files
    foreach(cc_folder ${opt_FOLDERS})
        file(GLOB_RECURSE folder_files "${cc_folder}/*")
        foreach(res_file ${folder_files})
            file(COPY ${res_file} DESTINATION "${opt_COPY_TO}/")
        endforeach()
    endforeach()
endfunction()
