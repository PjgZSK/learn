# 1. Transformations
## 1.1 How to move object 
- We can make objects move by changing their vertices and re-configuring their buffers  
each frame, but this is cumbersome and cost a lot.  
- There are much better ways to transform an object and that's using (multiple) matrix  
objects.  
## 1.2 Vectors
### 1.2.1 Vector definition
- A vector has a direction and a magnitude.  
- Vector mathematician description:  
$$\vec a = 
\begin{pmatrix}
x \\
y \\
z
\end{pmatrix}$$
- Vector can have any dimensions.  
### 1.2.2 Vector operations
#### 1.2.2.1 Scalar vector
- We can use 