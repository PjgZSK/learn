# OpenGL  
## What is OpenGL?
1. OpenGL is mainly considered an API(an Application Programming Interface) that provide us a large set of  
functions that we can use to manipulate graphics and images.  
2. However, OpenGL by itself is not an API, but merely a specification, developed and maintained by the  
Khronos Group.  
3. The people developing the actual OpenGL libraries are usually the graphics card manufacturers.  
4. Khronos publicly hosts all specification documents for all the OpenGL versions.  

## Core-profile and Immediate mode  
1. In the old days, using OpenGL meant developing in immediate mode(often referred to as the fixed  
function pipeline).  
2. Immediate mode is easy-to-use and understand, but it is also extremely inefficient and the developers  
did not have much control over how OpenGL does its calculations.  
3. For more control over their graphics, the specification start to deprecate immediate mode functionality  
from version 3.2 onward and started to motivated developers to develop in OpenGL's core-profile mode,   
which is a divition of OpenGL's specification that removed all old deprecated functionality.  
4. When use OpenGL's core-profile, OpenGL forces us to use modern practices. Whenever we try to use one  
of the OpenGL's deprecated functions, OpenGL will raises a error and stops drawing.  
5. The modern approach and OpenGL verison 3.3.  

## Extensions 
1. A great feature of OpenGL is its support of extensions.  
2. Whenever company comes up with a new technique or a new large optimization for rendering this  
is often found in an extension implemented in drivers.  
3. A graphics developer can still use those new techniques without having to wait for OpenGL to  
include the functionality in its future versions, simply by check if the extension is supported  
by the graphics card.  
4. When an extension is popular or very useful it eventually becomes part of future OpenGL version.  
```
if (GL_ARB_extension_name)
{
    // do cool new and modern stuff supported by graphics card  
}
else
{
    //extension is not supported : do it old way
}
```

## State machine  
1. OpenGL is by itself a large state machine : a collection of variables that define how OpenGL  
should currently operate. The state of OpenGL is commonly referred to as the OpenGL context.  
2. When use OpenGL, we often change its state by setting some options, manipulateing some buffers  
and then render using the current context.  
3. state-changing function : change the context and state-using function : perform some operations  
based on the current state of OpenGL.  
4. As long as you keep in mind that OpenGL is basically one large state machine, most of its  
functionality will make more sense.  

## Objects  
1. The OpenGL libraries are writen in C and allows for many derivation in other languages, but  
in its core it remains a C-library.  
2. Since many of C's language-constructs do not translate that well to other higher-level languages,  
OpenGL was developed with several abstractions in mind.  
3. One of those abstractions are objects in OpenGL.  
4. An object in OpenGL is a collection of options that represents a subset of OpenGL state.  
5. Workflow  
```
//creat object
unsigned int objectId = 0;
glGenObject(1, &objectId);
//bind/assign object to context
glBindObject(GL_WINDOW_TARGET, objectId);
//set options of object currently bound to GL_WINDOW_TARGET
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH, 800);
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
//set context target back to default
glBindObject(GL_WINDOW_TARGET, 0);
```

## Additional resources
* [opengl.org](https://www.opengl.org) : official website of OpenGL.  
* [OpenGL registry](https://www.opengl.org/registry/) : hosts the OpenGL specifications and   
extensions for all OpenGL versions.  




































