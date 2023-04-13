# Textures
1. We learned that to add more detail to our objects we can use colors for each vertex to create  
some interesting images. However, to get a fair bit of realism we'd have to have many vertices  
so we could specify a lot of colors. This takes up a considerable amount of extra overhead, since  
each model needs a lot more vertices and for each vertex a color attribute as well.  
2. What artists and programmers generally prefer is to use a texture. A texture is a 2D image(even  
1D and 2D texture exist) used to add detail to an object; Think of a texture as a piece of paper  
with a nice brick image(for example) on it neatly folded over your 3D house so it looks like your  
house has a stone exterior. Because we can insert a lot of detail in a single image, we can give  
the illusion the object is extremely detailed without having to specify extra vertices.  
*Next to images, textures can also be used to store a large collection of arbitrary data to send  
to the shaders, but we'll leave that for a different topic.*  
3. In order to map a texture to the triangle we need to tell each vertex of the triangle which part  
of the texture is corresponds to. Each vertex should thus have a texture coordinate associated with  
them that specifies what part of the texture image to sample from. Fragment interpolation then does  
the rest for the other fragments.  
4. Texture coordinates range from 0 to 1 in the x and y axis(remember that we use 2D texture images).  
Retrieving the texture color using texture coordinates is called sampling. Texture coordinates start  
at (0,0) for the lower left corner of a texture image to (1,1) for the upper right corner of a texture  
image.  
5. We specify 3 texture coordinate points for the triangle. We want the bottom-left side of the triangle  
to correspond with the bottom-left side of the texture so we use the (0,0) texture coordinate for the  
triangle's bottom-left vertex. The same applies to the bottom-right side with a (1,0) texture coordinate.  
The top of the triangle should correspond with the top-center of the texture image so we take (0.5, 1.0)  
as its texture coordinate. We only have to pass 3 texture coordinates to the vertex shader, which then passes  
those to the fragment shader that neatly interpolates all the texture coordinates for each fragment.  
```
float texCoords[] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    0.5f, 1.0f
};
```
Texture sampling has a loose interpolation and can be done in many different ways. It is thus our job  
to tell OpenGL how it should sample its textures.  

## Texture Wrapping
1. Texture coordinates usually range from (0,0) to (1,1) but what happens if we specify coordinates outside  
of this range ? The default bahavior of OpenGL is to repeat the texture images(we basically ignore the integer  
part of the floating point texture coordinates), but there are more options OpenGL offers :  
    * GL_REPEAT : The default behavior for texture. Repeats the texture image.  
    * GL_MIRRORED_REPEAT : Same as GL_REPEAT but mirrors the image with each repeat.  
    * GL_CLAMP_TO_EDGE : Clamps the coordinates between 0 to 1. The result is that higher coordinates become  
    clamped to the edge, resulting in a stretched edge pattern.  
    * GL_CLAMP_TO_BORDER : Coordinates outside the range are now given a user-specified border color.  
2. Each of the options have a different visual output when using texture coordinates outside the default range.  
Each of the aforementioned options can be set per coordinates axis(s,t(and r if you use 3D texture) equivalent  
to x,y,z) with the glTexParameter\* function :  
```
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
```
The first argument specifies the texture target; We're working with 2D texture so the texture target is GL_TEXTURE_2D.  
The second argument requires us to tell what option we want to set and for which texture axis; We want to configure  
it for both the S and T axis.  
The last argument requires us to pass in the texture wrapping mode we'd like and in this case OpenGL will set its  
texture wrapping option on the currently active texture with GL_MIRRORED_REPEAT.  
3. If we choose the GL_CLAMP_TO_BORDER option we should also specify a border color. This is done using the fv  
equivalent of the glTexParameter function with GL_TEXTURE_BORDER_COLOR as its option where we pass in a float  
array of the border's color value :  
```
float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
```

## Texture Filtering
1. Texture coordinates do not depend on resolution but can be any floating point values, thus OpenGL has to   
figure out which texture pixel(also known as a texel) to map the texture coordinate to. This becomes espectially  
important if you have a very large object and a low resolution texture. You probably guessed by now that  
OpenGL has options for this texture filtering as well. There are several options available but for now we'll  
discuss the most important options : GL_NEAREST and GL_LINEAR.  
2. GL_NEAREST(also known as nearest neighbor or point filtering) is the default texture filtering method of  
OpenGL. When set to GL_NEAREST, OpenGL selects the texel that center is closest to the texture coordinate.  
3. GL_LINEAR(also known as (bi)linear filtering) takes an interpolated value from the texture coordinate's  
neighboring texels. The smaller the distance from the texture coordinate to a texel's center, the more that  
texel's color contributes to the sampled color.  
4. GL_NEAREST results in blocked patterns where we can clearly see the pixels that form the texture while  
GL_LINEAR produces a smoother pattern where the individual pixels are less visible. GL_LINEAR produces a  
more realistic output, but some developers prefer a more 8-bit look and as a result pick the GL_NEAREST option.  
5. Texture filtering can be set for magnifying and minifying operations(when scaling up or downwards) so you  
could for example use nearest neighbor filtering when texture are scaled downwards and linear filtering for  
upscaled texture. We thus have to specify the filtering method for both options via glTexParameter\* . The  
code should look similar to setting the wrapping method :  
```
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
```

## Mipmaps

