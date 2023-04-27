# introduction to opengl
## 1. basic model
* commands, opengl and underlying graphics hardware
    > commands -> opengl -> underlying graphics hardware ( order model )  
    > commands -> opengl -> pipelining in parallel -> underlying graphics hardware ( pipelining model )

## 2. what is opengl
* goal
    > the goal of opengl is to provide an *abstraction layer* between your application  
    > and underlying graphics subsystem.

* abstraction level
    > opengl must strike a balance between too high and too low an abstraction level.

* GPUs
    > current GPUs consist of large numbers of small programmable processors called  
    > *shader cores* that run mini-programs called *shaders*.  
    > each core has a relatively low throughput,  
    > processing a single instruction of the shader in one or more clock cycles, and  
    > normally lacking advanced features such as out-of-order execution, branch prediction and  
    > super-scalar issues, and so on.

* shader
    > vertex shader  
    > tessellation control shader  
    > tessellation evaluation shader  
    > geometry shader  
    > fragment shader

## 3. core profile and compatibility profile
* core profile
    > removes a number of legacy features.

* compatibility profile
    > backward compatibility with all revisions of opengl back to version 1.0

* tips
    > use core profile if you can.

## 4. primitives, pipelines and pixels
* primitives
    > the fundamental unit of rendering.  
    > three basic renderable primitive types : points, lines and triangles.  
    > complex surfaces will be break into a very large number of triangles.  

* rasterizer
    > a dedicated hardware that convert the three-dimensional representation of a  
    > triangles into a series of pixels that need to be draw onto the screen.

* pipeline
    > *front end*    
    > processes vertices and primitives, eventually forming them into  
    > the points, lines and triangles that will be handed off to the rasterizer.  
    > this is known as primitive assembly.  
    > and after going through the rasterizer, the geometry converted from vector  
    > representation into a large number of independent pixels.

    > *back end*  
    > depth and stencil testing  
    > fragment shading  
    > blending  
    > updating of the output image

## 5. code resource
* [sb7](https://github.com/openglsuperbible/sb7code)
* [other](https://gitee.com/atom-l/OpenGl_Environments)
