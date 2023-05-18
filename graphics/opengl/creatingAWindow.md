
<!-- vim-markdown-toc GFM -->

* [Creating a window](#creating-a-window)
    * [GLFW](#glfw)
        * [Building GLFW](#building-glfw)
            * [CMake](#cmake)
            * [Compilation](#compilation)
        * [Our first project](#our-first-project)
        * [Linking](#linking)
        * [GLAD](#glad)
            * [Setting up GLAD](#setting-up-glad)
    * [Additional resources](#additional-resources)

<!-- vim-markdown-toc -->
# Creating a window  
1. The first thing we need to do before we start creating stunning graphics is to create an OpenGL context  
and an application window to draw in.  
2. However, those operations are specific per operating system and OpenGL is purposefully tries to abstract  
itself from these operations.  
3. This means we have to create a window, define a context and handle user input all by ourselves.  
4. Luckily, there are quite a few libraries out there that provide the functionality we seek, some specifically  
aimed at OpenGL.  
5. Those libraries save us all the operation-system specific work and give us a window and an OpenGL context  
to render in.  

## GLFW
1. GLFW is a library, written in C, specifically targeted at OpenGL.  
2. GLFW gives us bare necessities required for rendering goodies to the screen. It allow us to create an OpenGL  
context, define window parameters, and handle user input, which is plenty enough for our purpose.  

### Building GLFW  
1. GLFW can obtained from their webpage's [download](https://www.glfw.org/download.html) page.  
2. GLFW already has pre-compiled binaries and head files for Visual Studio 2012 up to 2019, but for  
completeness's sake we will compile GLFW ourselves from the source code. This is give you a feel for  
the process of compiling open-source libraries yourself as not every library will have pre-compiled  
binaries available. So let's download Source packege.  
For use source packege, we are only interested in a few items :  
    * The resulting libraries from compilation.  
    * The include folder.  
        3. Compiling the library from the source code guarantees that the resulting library is perfectly tailored  
        for your CPU/OS, a luxury pre-compiled binaries don't always provide(sometimes, pre-compiled binaries  
        are not available for your system).  
        4. The problem with providing source code to the open world however is that not every one use the same  
        IDE or building system for developing their application, which means the project/solution files provided  
        may not be compatible for other people's setup. So people have to setup their project/solution with  
        the given .c/.cpp and .h/.hpp files, which is cumbersome.  
        5. Exactly for those reasons there is a tool called CMake.  

#### CMake
1. CMake is a tool that can generate project/solution files of the user's choice(e.g. Visual Studio,  
Code::Block, Eclipse) from a collection of source code files using pre-defined CMake scripts.  
2. First we need download and install CMake which can be downloaded on their  
[download](http://www.cmake.org/cmake/resources/software.html) page.  
3. Once CMake is installed you can choose to run CMake from the command line or through their GUI.  
4. CMake requires a source code folder and a destination folder for binaries.  
5. Once the source and destination folder have been set, make *Configure* action so CMake can read  
the required setting and the source code.  
6. We then choose generator for the project.  
7. CMake will then display the possible building options to configure the resulting library. We can  
leave their default values and make *configure* action again to store the settings.  
8. Once the settings have been set, we make *Generate* action and the resulting project files will  
be generated.  

#### Compilation  
1. Open project/solution files, and build for target library. CMake should have automatically configured  
the solution so it compiles to the target library.  
2. Once we generated our library we need to make sure the IDE knows where to find the library and the  
include files for our OpenGL program.  
3. There are two common approches in doing this :  
1. We find the /lib and /include folders of the IDE/compiler and add the content of GLFW's /include   
folder to the IDE's /include folder ans similarly add glfw3.lib to the IDE's /lib folder. This works,  
but it is not the recommanded approach. It's hard to track your library and include files and a new  
installation of your IDE/compiler results in you have to do this all over again.  
2. Another approach(and recommend) is to create a new set of directories at a location of your choice  
that contains all the header files/libraries form third party libraries from to which you can refer to  
from your IDE/compiler. The requirement is, however, each time we create a new project we have to tell  
the IDE where to find those directories.  

### Our first project  
1. We use Visual Studio.  
Create a C++ empty project.  

### Linking  
1. In order for the project to use GLFW we need to link the library with our project. This can be done by  
specifying we want to use glfw3.lib in the linker settings, but our project does not yet know where to find  
glfw3.lib since we store our third party libraries in a different directory. We thus need to add this directory  
to our project first.  
2. Visual Studio  
    * Add your directories to *include directories* and *library directories*.  
    * Add glfw3.lib and opengl32.lib to the *additianal dependencies*.  
        3. OpenGL library on Windows : opengl32.lib(comes with Microsoft SDK, which is installed by default when  
        you install Visual Studio).  
        4. OpenGL library on Linux : libGL.so(linked by adding -lGL to your linker settings).  
        If you can't find the library you probably need to install any of the Mesa, NVidia or AMD dev packages.  
        5. Test  
        Once you had added both the GLFW and OpenGL library to the linker settings you can include the header  
        files for GLFW as follows :  
        ```
        #include <GLFW/glfw3.h>
        ```

### GLAD
1. Because OpenGL is really a standard/specification it is up to the driver manufacturer to implement  
the specification to a driver that the specific graphics supports.  
2. Since there are many different versions of OpenGL drivers, the location of most of its functions is   
not known at compile-time and needs to be queries at run-time.  
3. It is then the task of the developer to retrieve the location of the functions he/she needs and  
store them in function pointers for later use.  
4. Retrieving those location is [OS-Specific](https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions).  
5. There are libraries for this purpose as well where GLAD is a popular and up-to-date library.  

#### Setting up GLAD  
1. GLAD is a [open source](https://github.com/Dav1dde/glad) library that manages all that cumbersome work  
we talk about.  
2. GLAD has a different configuration setup than most common open source libraries. GLAD use a  
[web service](https://glad.dav1d.de/) where we can tell GLAD for which version of OpenGL we'd like to  
define and load all relevant OpenGL functions according to that version.  
3. Go to the [web service](https://glad.dav1d.de/), and make sure the language is set to C++, and in  
the API section select an OpenGL version of at least 3.3.  
Also make sure the profile is set to Core and that the Generate a loader option is ticked. ignore the  
extensions(for now) and click Generate to produce the resulting library files.  
4. GLAD by now should have provided you a zip file containing two include files, and s single glad.c file.  
Copy both include folders(glad ans KHR) into your include(s) directoy(or add an extra item pointing to  
these folders), and add the glad.c file to your project.  
5. Test  
```
#include <glad/glad.h>
```
Hit the compile button shouldn't give you any errors, at which point we're set to go for the next chapter  
where we'll discuss how we can actually use GLFW and GLAD to configure an OpenGL context and spawn a  
window. Be sure to check that all your include and library directories are correct and that the library  
names in the linker settings match the corresponding libraries.  

## Additional resources  
1. [GLFW: Window Guide](https://www.glfw.org/docs/latest/window_guide.html) : official GLFW guide on  
setting up and configuring a GLFW window.  
2. [Buiding applications](http://www.opengl-tutorial.org/miscellaneous/building-your-own-c-application/) :  
provides great info about the compilation/linking process of your application and a large list of  
possible errors(plus solutions) that may come up.  
3. [GLFW with Code::Blocks](http://wiki.codeblocks.org/index.php?title=Using_GLFW_with_Code::Blocks) :  
building GLFW in Code::Blocks IDE.  
4. [Running CMake](https://cmake.org/runningcmake/) : short review of how to run CMake on both  
Windows and Linux.  
5. [Writing a build system under Linux](https://learnopengl.com/demo/autotools_tutorial.txt) :  
an autotools tutorial by Wouter Verholst on how to write a build system in Linux.  
6. [Polytonic/Glitter](https://github.com/Polytonic/Glitter) :  
a simple boilerplate project that comes pre-configured with all relevant libraries;  
great for if you want a sample project without the hassle of having to compile all  
the libraries yourself.  

