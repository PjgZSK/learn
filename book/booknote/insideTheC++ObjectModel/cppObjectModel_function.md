# cpp object model/function
## 1. types of function member
* static member function
    > static member function will tranform into nonmember function directly 

* nonstatic member function
    > nonstatic member function will tranform into nonmember function by  
    > extra parameter `this`

* virtual member function
    > virtual member function will be called by *vptr*  
    > there is a optimization, when virtual member function is called without objection  
    > it will be called like a nonstatic member function. and this optimization will  
    > benefit inline virtual member function.

## 2. name mangling
> member name will add class and parameter list(for function member) to be unique.  
> name mangling will invalid if you declare `extern "C"`.  
> there is no industrial standard for name mangling.

## 3. virtual member function in inheritance
* runtime resolution
    > if we have one line of code below :  
    > `ptr->z()`  
    > what info the compiler need konw for realize a call of *virtual member function* ?  
    > 1. `z()` is a *virtual function* ?(this enough if not)  
    > 2. the *vtbl*  
    > 3. the index of `z()` in *vtbl*

* single inheritance
    > the mechanism of *vptr* and *vtbl* have a good operation.

* multiple inheritance
    > 


