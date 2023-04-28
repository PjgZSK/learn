# cmake buildsystem
## Introduction
1. A CMake-based buildsystem is organized as a set of high-level logical targets.  
2. Each target corresponds to an executable or library, or is a custom target containing  
custom commands.  
3. Dependencies between the targets are expressed in the buildsystem to determine the build  
order and the rules for regeneration in response to change.  

## Binary target
1. Executables and libraries are defined using the `add_executable()` and `add_library()` commands.  
2. The resulting binary files have approriate PREFIX, SUFFIX and extensions for the platform targeted.  
3. Dependencies between binary targets are expressed using the `target_link_libraries()` commands:  
```
add_library(archive archive.cpp zip.cpp lzma.cpp)
add_executable(zipapp zipapp.cpp)
target_link_libraries(zipapp archive)
```
`archive` is defined as a STATIC library that an archive containing objects compiled from `archive.cpp`,  
`zip.cpp` and `lzma.cpp`.  
`zipapp` is defined as an executable formed by compiling and linking `zipapp.cpp`.  
When linking the `zipapp` executable, the `archive` static library is linked in.  

## Binary Executables
1. The `add_executable` command defines an executable target.  
2. Commands such as `add_custom_command()`, which generates rules to be run at build time can transparently  
use an `EXECUTABLE` target as a `COMMAND` executable. The buildsystem rules will ensure that the executable  
is build before attemping to run the command.  

## Binary Library Types
### Normal Libraries
1. By default, the `add_library` command defines a `STATIC` library, unless a type is specified.  
2. A type can be specified when using the command:  
```
add_library(archive SHARED archive.cpp)
# or
add_library(archive STATIC archive.cpp)
```
3. In the context of the buildsystem definition as a whole, it is largely irrelevant whether particular  
libraries are SHARED or STATIC -- the commands, dependency specifications and other APIs work similarly  
regardless of the library type.  
4. The `MODULE` library type is dissimilar in that it is generally not linked to -- it is not used in the  
right-hand-side of the `target_link_libraries()` command. It is a type which is loaded as a plugin using  
runtime techniques.  
5. If the library does not export any unmanaged symbols(e.g. Windows resource DLL, C++/CLI DLL), it is  
required that the library not be a SHARED library because CMake expects SHARED libraries to export at  
least one symbol.  
### Apple Frameworks
1. A SHARED library may be marked with the `FRAMEWORK` target property to create an macOS or IOS Framework  
Bundle.  
2. A library with the `FRAMEWORK` target property should also set the `FRAMEWORK_VERSION` target property.  
3. The `FRAMEWORK_VERSION` property is typically set to the value of "A" by macOS conventions.  
4. The `MACOSX_FRAMWORK_IDENTIFIER` sets the `CFBundleIdentifier` key and it uniquely identifies the bundle.  
```
add_library(MyFramework SHARED MyFramework.cpp)
set_target_properties(MyFramework PROPERTIES
    FRAMEWORK TRUE
    FRAMEWORK_VERSION A
    MACOSX_FRAMWORK_IDENTIFIER org.cmake.MyFramework
)
```
### Object Libraries
```
add_library(archive OBJECT archive.cpp zip.cpp lzma.cpp)

add_library(archiveExtras STATIC $<TARGET_OBJECTS:archive> extras.cpp)

add_executable(test_exe $<TARGET_OBJECTS:archive> test.cpp)
```

## Build Specification and Usage Requirements
1. The `target_include_directories()`, `target_compile_definitions()` and `target_compile_options()` commands  
specify the build Specifications and the usage requirements of binary targets.  

