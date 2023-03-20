# Hello Triangle
## Quick Check
1. opengl quick check  
2. graphics pipeline  
3. shader  
4. the stages of graphics pipeline
5. vertex input  
6. vertex shader

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
    allow us to do some basic processing on the vertex attributes.  
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
* other  
    tessellation stage  
    transform feedback loop  
* in modern opengl we are required to defined at least a vertex and fragment shader of our own(there is no default vertex/fragment  
    shaders on the GPU)  

* normalized device coordinates(NDC)  
    NDC is in a small space where the x,y and z values vary from -1.0 to 1.0; all coordinates that fall outside this range  
        will be discarded/clipped and won't be visible on your screen.
    unlike usual screen coordinates, in NDC the positive y-axis in the up-direction and the (0,0) coordinates are at the  
        center of graph, instead of top-left.  
* glViewport  
    your NDC coordinates will then be transform to screen-space coordinates via the viewport transform using data you provided  
        with glViewport  
    the resulting screen-space coordinates are then transform to fragments as inputs to your fragment shader.  
    the function requires 4 coordinates for the left, bottom, right and top coordinates of your viewport rectangle. the coordinates  
        specified tell opengl how to map its NDC to *windows coordinates*(in the range as specified by the given coordinates)  
* define a triangle vertex data in NDC in a float array :  
    ```
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };        
    ```
* send vertex data at input to the first process of the graphics pipeline : vertex shader  
    1. create memory on the GPU where we store the vertex data  
    2. configue how opengl should interpret the memory  
    3. specify how to send the data to the graphics card  
* *vertex buffer objects(VBO)*  
    vbo is opengl object that has a unique ID.  
    we manage GPU's vertex memory by vbo that can store a large number of vertex data in GPU's memory. the advantage of using   
        those buffer objects is that we can send large batches of data all at once to the graphics card, and keep it there if  
        there's enough memory left, without having to send data one vertex at once.  
    send data to graphics cards form cpu is relatively slow, so wherever we can we try to send as much data as possible at once.  
* glGenBuffers  
    we can generate one with a buffer id using the *glGenBuffers* function :  
    ```
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    ```
* glBindBuffer  
    opengl has many types of buffer objects and the buffer type of vertex buffer object is GL_ARRAY_BUFFER.  
    we can bind the newly created buffer to the GL_ARRAY_BUFFER target with glBindBuffer function :  
    ```
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    ```
    from this point on any buffer calls we make(on the GL_ARRAY_BUFFER target) will be used to configure the  
        currently bound buffers, which is `VBO`.  
* glBufferData  
    so we can make a call to the glBufferData that copies the previously vertex data into the buffer's memory :  
    ```
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    ```
    the function allocates memory and stores data within the initialized memory in the currently bound buffer object.  
    the fourth parameter specifies how we want graphics card to manager the given data. this can take 3 forms :  
        1. *GL_STREAM_DRAW* : the data is set only once and used by GPU at most a few times.  
        2. *GL_STATIC_DRAW* : the data is set only once and used by many times.  
        3. *GL_DYNAMIC_DRAW* : the data is changed a lot and used by many times.  
    the position data of the triangle does not change, is used a lot, and stay the same for every render call  
        so its usage type should best be *GL_STATIC_DRAW*.  


## Question
* how graphics cards work with parallel graphics pipeline ?

link : https://learnopengl.com/Getting-started/Hello-Triangle
