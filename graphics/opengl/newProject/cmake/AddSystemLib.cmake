macro(depend)
    # confim the libs, prepare to link
    set(PLATFORM_SPECIFIC_LIBS)

    if(WIN32)
        list(APPEND PLATFORM_SPECIFIC_LIBS opengl32)
    elseif(APPLE)
        include_directories(/System/Library/Frameworks)
        list(APPEND PREBUILT_SPECIFIC_LIBS GLFW3)

        find_library(COCOA_LIBRARY Cocoa)
        find_library(OPENGL_LIBRARY OpenGL)
        find_library(IOKIT_LIBRARY IOKit)
        list(APPEND PLATFORM_SPECIFIC_LIBS
             ${COCOA_LIBRARY}
             ${OPENGL_LIBRARY}
             ${IOKIT_LIBRARY}
             )
    endif()
endmacro()

macro(add_system_depends target)
    depend()
    foreach(platform_lib ${PLATFORM_SPECIFIC_LIBS})
        target_link_libraries(${target} ${platform_lib})
    endforeach()

endmacro()

