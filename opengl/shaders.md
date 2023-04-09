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

