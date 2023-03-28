# Hello Window
1. First we create a .cpp file and add glad and glfw header.  
```
#include <glad/glad.h>
#include <GLFW/glfw3.h>
```
Be sure to include GLAD before GLFW. The include file for GLAD includes the required  
OpenGL headers behind the scenes(like GL/gl.h) so be sure to include GLAD before other  
header files that require OpenGL(like GLFW).  
2. Next we will create the main function where we will instantiate the GLFW window.  
```
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 

    return 0;
}
```
In the main function we first initialize GLFW with glfwInit, after which we can configure  
GLFW using glfwWindowHint.  
The first argument of glfwWindowHint tell us what option we want to configure, where we can  
select the option from a large enum of possible options prefixed with GLFW_.  
The second argument is an integer that set the value of our option.  
A list of all possible options and its corresponding values can be found at  
[GLFW's window handling](https://www.glfw.org/docs/latest/window.html#window_hints) documentation.  
If you try to run the application now and it gives you a lot of undefined reference errors it  
means you didn't successfully link the GLFW library.  
3. Now we use OpenGL version 3.3 so we set the major and minor version both to 3.  
We also tell GLFW we want to explicitly use the core-profile. Telling GLFW we want  
to use the core-profile means we'll get access to a smaller subset of OpenGL features  
without backwards-compatible features we no long need.  
4. Note that on Max OS X you need to add  
```
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
```
to your initialization code for it to work.  
5. Next we're requried to create a window object. This window object holds all the  
windowing data and is required by most of GLFW's other function.  
```
GLFWwindow* window = glCreateWindow(800, 600, "LearningOpenGL", NULL, NULL);
if (window == NULL)
{
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
}
glfwMakeContextCurrent(window);
```
The glCreateWindow function requires the window width and height as its first  
two arguments respectively. The function return a GLFWwindow object that we'll  
later need for other GLFW operations.  
After that we tell GLFW to make the context of our window the main context on the  
current thread.  

## GLAD  
1. In the previous chapter we mentioned that GLAD manages function pointers for  
OpenGL so we want to initialize GLAD before we call any OpenGL function :  
```
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
}
```
We pass GLAD the function to load the address of the OpenGL functions pointers  
which is OS-speicfic. GLFW gives us glfwGetProcAddress that defines the correct  
function based on which OS we're compiling for.  

## Viewport




















































