macro(depend)
    # confim the libs, prepare to link
    set(PLATFORM_SPECIFIC_LIBS)

    if(WINDOWS)
        list(APPEND PLATFORM_SPECIFIC_LIBS opengl32)
    elseif(APPLE)

        include_directories(/System/Library/Frameworks)
        if(MACOSX)
            list(APPEND PREBUILT_SPECIFIC_LIBS GLFW3)

            find_library(COCOA_LIBRARY Cocoa)
            find_library(OPENGL_LIBRARY OpenGL)
            list(APPEND PLATFORM_SPECIFIC_LIBS
                 ${COCOA_LIBRARY}
                 ${OPENGL_LIBRARY}
                 )
endmacro()

macro(use_libs_depend target)
    depend()
    foreach(platform_lib ${PLATFORM_SPECIFIC_LIBS})
        target_link_libraries(${target} ${platform_lib})
    endforeach()

endmacro()

