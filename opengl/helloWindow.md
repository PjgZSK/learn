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
1. We have to tell OpenGL the size of the rendering window so OpenGL knows how  
we want to display the data and coordinates with respect to the window. We can  
set those dimensions via the glViewPort function :  
```
glViewPort(0, 0, 800, 600);
```
The first parameters of glViewPort set the location of the lower left cornor of  
the window.  
The third and fourth parameter set the width and height of the rendering window  
in pixels, which we set equal to GLFW's window size.  
2. We could actually set the viewport dimensions at the values smaller than GLFW's  
dimensions; then all the OpenGL rendering would be displayed in a smaller window  
and we could for example display other elements outside the OpenGL viewport.  
3. Behind the scenes OpenGL uses the data specified via glViewPort to transform  
the 2D coordinates it processed to coordinates on your screen.  
For example, a processed point of location (-0.5, 0.5) would (as its final transform)  
be mapped to (200, 450) in screen coordinates. Note that processed coordinates in  
OpenGL are between -1 and 1 so we effectively map form the range (-1, 1) to (0, 800)  
and (0, 600).  
4. However, the moment a user resizes the window the viewport should be adjusted as  
well. We can register a callback function on the window that gets called each time  
the window is resized. This resize callback function has the following prototype.  
```
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
```
The function takes a GLFWwindow as its first argument and two integers indicating  
the new window dimensions.  
```
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewPort(0, 0, width, height);
}
```
We do have to tell GLFW we want to call this function on every window resize  
by registering it :  
```
glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
```
When the window is first displayed framebuffer_size_callback gets called as  
well with the resulting window dimensions.  
5. For retina displays width and height will end up significantly higher than  
the original input values.  
6. There are many callbacks functions we can set to register our own functions.  
For example, we can make a callback function to process joystick input changes,  
process error messages etc. We register the callback functions after we've created   
the window and before the render loop is initiated.  

## Ready your engines  
1. We don't want the application to draw a single image and then immediately quit  
and close the window. We want the application to keep drawing images and handling  
user input until the program has been explicitly told to stop.  
2. For this reason we have to create a while loop, that we now call the render loop,  
that keeps on running until we tell GLFW to stop. The following code shows a very  
simple render loop :  
```
while (!glfwWindowShouldClose(window))
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
```
3. The glfwWindowShouldClose checks at the start of each loop iteration if GLFW  
has been instructed to close. If so, the function return true and render loop  
stops running, after which we can close the application.  
The glfwPollEvents function checks if any events are triggered (like keyboard  
input or mouse movement event), update the window state, and calls the  
corresponding functions(which we can register via the callback methods).  
The glfwSwapBuffers will swap the color buffer(a large 2D buffer that contains  
color values for each pixel in GLFW's window) that is used to render to during  
this render iteration and show it as output to the screen.  
4. Double buffer  
When an application draws in a single buffer the resulting image may display  
flickering issues. This is because the resulting output image is not draw  
in an instant, but drawn pixel by pixel and usually from left to right and  
top to bottom. Because this image is not displayed at an instant to the user  
while still being rendered to, the result may contain artifacts.  
5. To circumvent those issues, windowing applications apply a double buffer  
for rendering. The *front* buffer contains the final output image that is  
shown at the screen, while all the rendering commands draw to the back buffer.  
6. As soon as all the rendering commands are finished we swap the back buffer  
to the front buffer so the image can be displayed without still being rendered  
to, removeing all the aforementioned artifacts.  

## One last thing  
1. As soon as we exit the render loop we would like to properly clean/delete  
all of GLFW's resources that were allocated. We can do this via the   
glfwTerminate function that we call at the end of the main function.  
```
glfwTerminate();
return 0;
```
This will clean all the resources and properly exit the application.  
Now try to compile your application and if everything went well you should  
see the black empty output.  

## Input  
1. We also want to have some form of input control in GLFW and we can achieve  
this with several of GLFW's input functions. We'll be using GLFW's glfwGetKey  
function that takes the window as input together with a key. The function  
returns whether this key is currently being pressed. We're creating a processInput  
function to keep all input code organized :  
```
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
     glfwSetWindowShouldClose(window, true);
}
```
2. Here we check whether the user has pressed the escape key (if it's not pressed,  
glfwGetKey returns GLFW_RELEASE). If the user did press the escape key, we close  
GLFW by setting its WindowShouldClose property to true using glfwSetWindowShouldClose.  
The next condition check of the main while loop will then fail and the application closes.  
3. We then call processInput every iteration of the render loop :  
```
while (!glfwwindowshouldclose(window))
{
    processinput(window);

    glfwswapbuffers(window);
    glfwpollevents();
}

```
This give us an easy way to check for specific key presses and react accordingly  
every frame. An iteration of the render loop is more commonly called a frame.  

## Rendering  
1. we want to place all the rendering commands in the render loop, since we want  
to execute all the rendering commands each iteration or frame of the loop.  
This would look a bit like this :  
```
// render loop
while (!glfwwindowshouldclose(window))
{
    // input
    processinput(window);
    
    //rendering commands here
    ...

    //check and call events and swap the buffers
    glfwpollevents();
    glfwswapbuffers(window);
}
```
We can clear the screen's color buffer using glClear where we pass in buffer  
bit to specify which buffer we would like to clear. The possible bit we can  
set are GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT and GL_STENCIL_BUFFER_BIT.  
Right now we only care about the color values so we only clear the color  
buffer.  
```
glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
```
Whenever we call glClear and clear the color buffer, the entire color buffer  
will be filled with the color as configured by glClearColor.  
2. As you may recall from the OpenGL chapter, the glClearColor function is a  
state-setting function and glClear is a state-using function in that it uses  
the current state to retrieve the clearing color from.  
3. So right now we got everything ready to fill the render loop with lots of  
rendering calls.


