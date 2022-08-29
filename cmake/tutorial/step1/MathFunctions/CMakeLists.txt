add_library(MathFunctions SHARED mysqrt.cpp)
target_include_directories(MathFunctions 
                        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )
