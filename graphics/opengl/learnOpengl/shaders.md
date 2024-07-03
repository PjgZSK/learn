# Shaders
1. As mentioned in the Hello Triangle chapter, shaders are little programs that rest on the GPU.  
2. These programs are run for each specific section of the graphics pipeline. In base scene, shaders are  
nothing more than programs transforming inputs to outputs.  
3. Shaders are also very isolated programs in that they're not allowed to communicate with each other;  
The only communication they have is via their inputs and outputs.  
4. In the previous chapter we have briefly touched the surface of shaders and how to properly use them.  
We will now explain shaders, and specifically the OpenGL Shader Language, in a more general fashion.  

## GLSL
1. Shaders are writen in a C-like language GLSL. GLSL is tailored for use with graphics and contains  
useful features specifically targeted at vector and matrix manipulation.  
2. Shaders always begin with a version declaration, followed by a list of input and output variables,  
uniforms and its main function. Each shader's entry point is at its main function where we process  
any input variables and output the results in its output variables.  
```
#version version_number
in type in_variable_name;
in type in_variable_name;

out type out_variable_name;

uniform type uniform_name;

void main()
{
    // ... process input and do some weird graphics stuff  
    ...
    // ... output processed stuff to output variables  
    out_variable_name = weird_stuff_we_processed;
}
```
3. When we're talking specifically about vertex shader each input variable is also known as a vertex  
attribute. There is a maximum number of the vertex attributes we're allowed to declare limited by  
hardware. OpenGL guarantees there are always at least 16 4-component vertex attributes variables, but  
some hardware may allow for more which you can retrieve by querying GL_MAX_VERTEX_ATTRIBS.  
```
int nrAttributes;
glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
std::cout << "The maximum number of vertex attributes variables supported: " << nrAttributes << std::endl;
```
This often returns the minimum of 16 which should be more than enough for most purpose.  

## Types
1. GLSL has, like other language, data type specifing what kind of variable we want work with.  
GLSL has most of defalut basic type we know form other language like C : int, float, double, uint and  
bool. GLSL also features two container types that we'll be using a lot, namely vectors and matrices.  
We will discuss matrices in a later chapter.  

### Vectors
1. A vector in GLSL is a 2, 3 or 4 component container for any of the basic types just mentioned.  
They can take the follow forms :  
    * vecn : the default vector of n floats  
    * ivecn : a vector of n integers  
    * bvecn : a vector of n bools  
    * uvecn : a vector of n unsigned integers  
    * dvecn : a vector of n double components  
Most of time we will be using the basic vecn because floats are most sufficient for most of our purpose.  
2. Component of a vector can be accessed via vec.x where x is the first component of the vector.  
You can use .x, .y, .z, and .w to access their first, second, third and fourth component respectively.  
GLSL also allows you to use rgba for colors or stpq for texture coordinates, accessing the same components.  
3. The vector datatype allows for some interesting and flexible component selection called *swizzling*.  
Swizzling allows us to use syntax like this :  
```
vec2 someVec;
vec4 differentVec = someVec.xyxx;
vec3 anotherVec = differentVec.zyw;
vec4 otherVec = someVec.xxxx + anotherVec.zyxz;
```
You can use any combination of up to 4 letters to create a new vector(of the same type) as long as  
the origin vector has those components. It is not allowed to access .z component of a vec2 for example.  
4. We can also pass vectors as arguments to a different vector constructor calls, reducing the number  
of arguments required :  
```
vec2 vect = vec2(0.2, 0.5);
vec4 result = vec4(vec2, 0, 0);
vec4 otherResult = vec4(result.xyz, 1.0);
```
Vectors are thus flexible datatype that we can use for all kinds of input and output. Throughout the  
book you'll see plenty of examples of how we can creatively manage vectors.  

## Ins and Outs
1. Shaders are nice little programs on their own, but they are part of a whole and for that reason  
we want to have inputs and outputs on the individual shaders so that we can move some staff around.  
2. GLSL defined the in and out keyword specifically for that purpose. Each shader can specify inputs  
and outputs using those keywords and wherever an output variable matches with an input variable of  
next shader stage they're passed along. The vertex and fragment shader differ a bit though.  
3. The vertex shader should receive some form of input otherwise it would be pretty ineffective.  
The vertex shader differs in its input, in that it receives its input straight from the vertex data.  
To define how the vertex data is organized we specify the input variables with location metadata so  
we can configure the vertex attributes in CPU. We're seen this in the previous chapter as   
layout (location = 0). The vertex shader thou requires extra layout specification for its input so  
we can link it with the vertex data.  
It is also possible to omit the layout (location = 0) specifier and query for the attribute locationd  
in yout OpenGL code via glGetAttribLocation, but I'd prefer to set them in the vertex shader. It is  
easier to understand and saves you (and OpenGL) some work.  
4. The other exception is that the fragment shader requires a vec4 color output variable, since the  
fragment shader needs to generate a final output color. If you fail to specify an output color in  
your fragment shader, the color buffer output for those fragments will be undefined(which usually  
means OpenGL will render them either white or black.  
5. So if we want send data from one shader to the other we'd have to declare an output in the sending  
shader and a similar input in receiving shader. When the type and name are equal on both sides OpenGL  
will link those together and then it is possible to send data between shaders(this is done when linking  
a program object).  
6. To show you how this works in practice we're going to alter the shaders from the previous chapter to  
let the vertex shader decide the color for the fragment shader.  
7. In practice :   
*Vertex shader*  
```
#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute positon 0
out vec4 vertexColor; // specify a color output to the fragment shader
void main()
{
    gl_Position = vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to dark-red color
}
```
*Fragment shader*  
```
#version 330 core
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)
out vec4 FragColor;
void main()
{
    FragColor = vertexColor;
}
```
You can see we declared a vertexColor variable as a vec4 output in the vertex shader and  
we declare a similar vertexColor variable as a vec4 input in the fragment shader.  
Since they both have the same name and type, the vertexColor in the fragment shader is linked to  
the vertexColor in the vertex shader.  
8. There we go! We just managed to send a value from the vertex shader to the fragament shader.  
Let's spice it a bit and see if we can send a color from our application to the fragment shader.  

## Uniforms
1. Uniforms are another way to pass data from our application on the CPU to the shaders on the GPU.  
2. Uniforms are however slightly different compared to vertex attributes. First of all, uniforms are  
global. Global, means that a uniform is unique per shader program object, and can be accessed from  
any shader at any stage in the shader program. Second, whatever you set the uniform value to, uniforms  
will keep their values until they're either reset or updated.  
3. To declare a uniform in GLSL we simply add the uniform keyword to a shader with a type and a name.  
From that point on we can use the newly created uniform in the shader.  
4. Let's see this time we can set color of triangle via a uniform :  
```
#version 330 core
uniform vec4 ourColor; // we set this variable in the OpenGL code.
out vec4 fragColor;
void main()
{
    fragColor = ourColor;
}
```
We decalred a uniform vec4 ourColor in the fragment shader and set the fragment's output color to  
the content of this uniform value. Since uniforms are global variables, we can define them in any  
shader stage we'd like so no need to go through vertex shader again to get something to the fragment  
shader. We're not using this uniform in the vertex shader so there's no need to define it there.  
*If you declare a uniform that isn't used anywhere in your GLSL code the compiler will silently  
remove the variable from the compiled version which is the cause for several frustrating errors;  
Keep it in mind!*  
5. The uniform is currently empty; We haven't added any data to the uniform yet so let's try that.  
We first need to find the index/location of the uniform attribute in our shader. Once we have the  
index/location of the uniform, we can update its value. Instead of passing a single color to the  
fragment shader, let's spice things up by gradually changing color over time :  
```
float timeValue = glfwGetTime();
float greenValue = (sin(timeValue) / 2) + 0.5f;
int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
glUseProgram(shaderProgram);
glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
```
6. First, we retrieve the running time in seconds via glfwGetTime(). Then we vary the color in the  
range from 0.0 to 1.0 by using the sin function and store the result in greenValue.  
Then we query for the location of the ourColor uniform using glGetUniformLocation. We supply the  
shader program and the name of the uniform(that we want to retrieve location from) to the query  
function. If glGetUniformLocation returns -1, it could not find the location. Lastly we can set  
the uniform value using the glUniform4f function.  
Note that find the uniform location does not require you to use the program first, but updating  
a uniform does require you to first use the program(by calling glUseProgram), because it sets  
the uniform on the currently active shader program.  
7. Because OpenGL is in its core a C library it does not have native support for function overloading,  
so whenever a function can be called with different types OpenGL defines new functions for each type  
required;  
glUniform is a perfect example of this. The function requires a specific postfix for the type of the  
uniform you want to set. A few of the possible postfixes are :  
    * f : the function expects a float as its value.
    * i : the function expects an int as its value.
    * ui : the function expects an unsigned int as its value.
    * 3f : the function expects 3 floats as its value.
    * fv : the function expects a float vector/array as its value.  
Whenever you want to configure an option of OpenGL simply pick the overloaded function that corresponding  
with your type. In our case we want to set 4 floats of the uniform individually so we pass our data  
via glUniform4f(note that we also could've used the fv version).  
8. Now that we know how to set the values of uniform variables, we can use them for rendering.  
If we want to the color to gradually change, we want to update this uniform every frame, otherwise the  
triangle would maintain a single solid color if we only set it once. So we calculate the greenValue  
and update the uniform each render iteration :  
```
while (!glfwWindowShouldClose(window))
{
    // input
    processInput();

    // render
    // clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // be sure to activate the shader
    glUseProgram(shaderProgram);

    // update the uniform color
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
    
    // now render the triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // swap buffers and poll IO events
    glfwSwapBuffers(window);
    glfwPollEvents();
}
```
9. As you can see, uniforms are a useful tool for setting attributes that may  
change every frame, or for interchanging data between your application and  
shaders, but what if we want to set a color for each vertex ? In that case, we'd  
have to declare as many uniforms as we have vertices. A better solution would  
be to include more data in the vertex attributes which is what we're going to  
do now.  

## More attributes!
1. We saw in the previous chapter how we can fill a VBO, configure vertex attributes  
and store it all in a VAO. This time, we also want to add color data to the vertex  
data.  
2. We're going to add color data as 3 floats to the vertices array. We assign a red,  
green and blue color to each of the corners of our triangle respectively :  
```
float vertices[] = {
    // position        // color
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
   -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
    0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // top
};
```
Since we now have more data to send to vertex shader, it is necessary to adjust the  
vertex shader to also receive our color value as a vertex attribute input.  
Note that we set the location of the aColor attribute to 1 with the layout specifier :  
```
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
}
```
3. Since we no long use a uniform for the fragment's color, but now use the ourColor output  
variable we'll have to change the fragment shader as well :  
```
#version 330 core
out vec4 fragColor;
in vec3 ourColor;
void main()
{
    fragColor = vec4(ourColor, 1.0);
}
```
4. Because we added another vertex attribute and the update the VBO's memory we have to re-configure  
the vertex attribute pointers.  
```
// position attribute
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices), 6 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);
// color attribute
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertices), 6 * sizeof(float), (void*)(3 * sizeof(float)));
glEnableVertexAttribArray(1);
```
The few arguments of glVertexAttribPointer are relatively straightforward. This time we are  
configuring the vertex attribute on attribute location 1. The color values have a size of 3 floats  
and we do not normalize the values.  
Since we now have two vertex attributes we have to re-calculate stride value. To get the next attribute  
value(e.g. the next x component of the position vector) in the data array we have to move 6 floats  
to the right, three for the position values and three for the color values. This gives us a stride  
of 6 times size of a float in bytes(=24bytes).  
Also, this time we have to specify an offset. For each vertex, The position attribute is first so  
we declare an offset of 0. The color attribute starts after the position so the offset is 3 * sizeof(  
float) in bytes(=12bytes).  
5. The image may not be exactly what you would expect, since we only supply 3 colors, not the huge color  
palette we're seeing right now. This is all result of something called fragment interpolation in the  
fragment shader.  
When rendering a triangle the rasterization stage usually results in a lot more fragments than vertices  
originlly specified. The rasterizer then determines the positions of each of those fragment based on  
where they reside on the triangle shape. Based on the positions, it interpolates all the fragment shader's  
input variables.  
Say for example we have a line where the upper point has a green color and the lower point a blue point.  
If the fragment shader is run at a fragment that resides around a position at 70% of the line, its resulting  
color input attribute would then be a linear combination of green and blue; To more precise : 30% blue and  
70% green.  
6. This is exactly what happened at the triangle. We have 3 vertices and thus 3 colors, and judging from  
the triangle's pixels it probably contains around 50000 fragments, where the fragment shader interpolated  
the colors among those pixels.  
If you take a good look at the colors you'll see it all makes sense : red to blue first gets to purple and  
then to blue. Fragment interpolation is applied to all the fragment shader's input attributes.  

## Our own shader class 
1. Writing, compiling and managing shader can be quite cumbersome. As a final touch on the shader subject  
we're going to make our life a bit easier by building a shader class that reads shaders from disks,   
compiles and links them, checks for errors and is easy to use.  
This also gives you a bit of an idea how we can encapsulate some of the knowledge we learned so far into  
useful abstract objects.  
2. We will create the shader class entirely in a header file, mainly for learning purposes and portability.  
Let's start by adding the required includes and by defining the class structure :  
```
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.g> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, bool value) const;
    void setFloat(const std::string& name, bool value) const;
};

#endif
```
We used several preprocessor directives at the top of the header file. Using these little lines  
of code informs your compiler to only include and compile this header file if it hasn't been  
included yet, even if multiple files include the shader header. This prevents linking conflicts.  
3. The shader class holds the ID of the shader program. Its constructor requires the file paths  
of the source code of the vertex and fragment shader respectively that we can store on disk as  
simple text files. To add a little extra we also add sevaral utility functions to ease our lives  
a little : use activates the shader program, and all set functions requery a uniform location and  
set its value.  
### Reading from file
1. We're using C++ filestreams to read the content from the file into several string objects :  
```
Shader(const char* vertexPath, const char* fragmentPath)
{
    // 1. retrieve the vertex/fragment source code from filepath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions : 
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into stream
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    [...]
```
2. Next we need to compile and link the shaders. Note that we're also reviewing if compilation/linking  
failed and if so, print the compile-time errors. This is extremely useful when debugging(you are going  
to need those error logs eventually) :  
```
// 2. compile shaders
unsigned int vertex, fragment;
int success;
char infoLog[512];

// vertex Shader
vertex = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertex, 1, &vShaderCode, NULL);
glCompileShader(vertex);
// print compile error if any
glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
if (!success)
{
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
}

// similiar for Fragment Shader
[...]

// shader Program
ID = glCreateProgram();
glAttachShader(ID, vertex);
glAttachShader(ID, fragment);
glLinkProgram(ID);
// print link error if any
glGetProgramiv(ID, GL_LINK_STATUS, &success);
if (!success)
{
    glGetProgramInfoLog(ID, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
}

// delete the shaders as they're linked into our program and no longer necessary
glDeleteShader(vertex);
glDeleteShader(fragment);
```
The use function is straightforward :  
```
void use()
{
    glUseProgram(ID);
}
```
Similarly for any of the uniform setter functions :  
```
void setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void setFloat(const std::string& name, float value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
```
3. And there we have it, a completed shader class. Using the shader class is fairly easy;  
We create a shader object once and from that point on simply start using it :  
```
Shader ourShader("path/to/shaders/shader.vs", "path/to/shaders/shader.fs");
[...]
whiel(...)
{
    ourShader.use();
    ourShader.setFloat("someUniform", 1.0f);
    DrawStuff();
}
```
Here we stored the vertex and fragment shader source code in two files called shader.vs and  
shader.fs. You're free to name your shader files however you like; I personally find the extensions  
.vs and .fs quite intuitive.  

## Exercises
1. Adjust the vertex shader so that the triangle is upside down.  
2. Specify a horizontal offset via u uniform and move the triangle to the right side of the screen in  
the vertex shader using this offset value.  
3. Output the vertex position to the fragment shader using the out keyword and set the fragment's color  
equal to this vertex position (see how even the vertex position values are interpolated across the triangle).  
Once you managed to do this; Try to answer the following question : why is the bottom-left side of our  
triangle black ?  

