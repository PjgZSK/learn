cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.0)

# generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(TutorialConfig.h.in TutorialConfig.h)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
endif()

# add the executable
add_executable(Tutorial tutorial.cpp)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC
                            "${PROJECT_BINARY_DIR}"
    )

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" 
    DESTINATION include)

enable_testing()

add_test(NAME Runs COMMAND Tutorial 25)

add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
    PROPERTIES PASS_REGULAR_EXPRESSION "please input a number !"
    )

function(do_test target arg result)
    add_test(NAME T${arg} COMMAND ${target} ${arg})
    set_tests_properties(T${arg}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result}
        )
endfunction()

do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is (-nan|nan|0)")
do_test(Tutorial 0.0001 "0.0001 is 0.01")
