# Hello Triangle
## Quick Check
1. opengl quick check  
2. graphics pipeline  
3. shader  
4. the stages of graphics pipeline

* opengl is 3d and screen or windows is 2d  
* a large part of opengl's work is about transforming all 3d coordinates to 2d pixels than fit your screen  

* graphics pipeline of opengl manage the process of transforming 3d coordinates to 2d pixels  
* graphics pipeline :  
    1. transforming 3d coordinates to 2d coordinates  
    2. transforming 2d coordinates into actual colored pixels  
* the graphics pipeline can divided into serveral steps where each steps requires the output of previous step as its input  

* all of the steps are highly specialized and can easily to be executed in parallel  
* because of parallel nature, graphics cards of today have thousands of small process cores to   
    quickly process your data within the graphics pipeline.  
* the processing cores run small programs on the GPU for each step of the pipeline  
* these small programs are called shaders  
* some of those shaders are configurable by the developer which allows us to write our own shaders to   
    replace the existing default shaders  
* shaders are written by OpenGL Shading Language(GLSL)  

* abstract representation of all stages of graphics pipeline(note that italic sections represent sections where we can inject our own shaders)  : 
    input : vertex data  
    stages : *vertex shader* -> shape assemblely -> *geometry shader* -> rasterization -> *fragment shader* -> tests and blending  
* vertex data is a list of 3d coordinates than should form a triangle and is represented using vertex attributes that can contain any data  
    we like, but for simplicity's sake let's assume that each vertex consists of just a 3d position and some color value.  
* primitives  
    for opengl to know what to make of your collection of coordinates and color values opengl requires you to hint what kind of render types  
    you want to form with the data. those hints are called primitives and are gived to opengl while calling ang of the drawing commands.  
    some of these hints are GL_POINTS, GL_TRIANGLES and GL_LINE_STRIP.  
* vertex shader :  
    vertex shader takes as input a single vertex  
    the main purpose of the vertex shader is to transform 3d coordinates into different 3d coordinates and  
    us to do some basic processing on the vertex attributes.  
* geometry shader :  
    the output of the vertex shader stage is optionally passed to the geometry shader.  
    the geometry shader takes as input a collection of vertices that form a primitives and  
        has ability to generate other shapes by emitting new verteces to form new(or other) primitive(s).  
* primitive assemblely :  
    the primitive assemblely stage takes as input all the vertices form the vertex or geometry shader that form one  
        or more primitives and assembles all the points in the primitive shape given.  
* rasterization :  
    the output of the geometry shader is then passed on to the rasterization stage where is maps  
        the resulting primitives to the corresponding pixels on the final screen, result in fragments  
        for fragment shader to use.  
    before the fragment shaders run, *clipping* is performed.  
    clipping discard all fragments that are outside your view, increasing performance  
* fragment shader :  
    *a fragment in opengl is all the data required for opengl to render a single pixel*  
    the main purpose of fragment shader is to calculate the final color of a pixel and this  
        is usually the stage where all the advanced opengl effect occur.  
    usually the fragment shader contains data about 3d scene that it can use to calculate the final pixel color(like lights,  
        shadows, color of the light and so on.)  
* alpha test and blending :  
    when all corresponding color values have been determined, the final object will then pass through one more stage that  
        we call the alpha test and blending stage.  
    the stage check the corresponding depth(and stencil) value of fragment and use those to check if the resulting fragment  
        is in front of or behind other objects and should be discarded accordingly  
    the stage also check for alpha values(alpha values define the opacity of an object) and blends the objects accordingly.  

## Question
* how graphics cards work with parallel graphics pipeline ?

link : https://learnopengl.com/Getting-started/Hello-Triangle
