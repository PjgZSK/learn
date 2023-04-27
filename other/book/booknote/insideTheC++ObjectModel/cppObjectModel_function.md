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
    > ```
    > class Base1;
    > class Base2;
    > class Derived : public Base1, public Base2;
    > ```
    
    > **virtual destructor**  
    > conside code below  
    > ```
    > Derived* pd = new Derived();
    > delete pd;//no offset call
    > 
    > Base2* pb2 = new Derived();
    > delete pb2;//offset call
    > ```
    > `pb2` point to `Base2` in `Derived`, and of course we need `Derived` address for right `this` pointer.  
    > so `delete pb2` is a *runtime operation* becase the address offset defined by true type of  
    > `pb2` pointed object.  
    > how to solve it ?  
    > 1. expand *virtual table slot*, every slot contain a virtual function address and offset.  
    > 2. *thunk*, slot can point to a thunk. thunk is some assembly code to adjust address.  
    > and for no offset call, you need different *vtbl*, for offset call and no offset call.  
    > there is a optimization for multiple *vtbl* that merge multiple *vtbl* to one by add a  
    > *vtbl* offset, in this case, every class only has one virtual table.
    
    > **base class virtual function call**  
    > conside code below
    > ```
    > Derived* pd = new Derived();
    > pd->Base2VFunc();//calss base2's virtual function 
    > ```
    > this is similar to **virtual destructor**

    > **override virtual function with different return**  
    > conside code below  
    > ```
    > /*
    >  * virtual Base1* Base1::clone()
    >  * virtual Base2* Base2::clone()
    >  * virtual Derived* Derived::clone()
    > */
    > Base2* pb2 = new Derived();
    > Base2* pb22 = pb2->clone();
    > ```
    > there are two offset call.

    > different compiler has different solution to multiple inheritance. and  
    > above solution just is a kind of reference. you can use code to explore compiler's  
    > solution. but read official documents first is more recommended.

## 4. virtual member function in virtual inheritance
* complex, no idea about this.

## 5. pointer to member function
* skip.

## 6. inline function
* define
    > the keyword `inline` is a request that if compiler think the function can expanded by a expression reasonablely,  
    > the keyword `inline` is valid, otherwise is invalid.

* by-effect
    > if inline function has local variable, repeat call it will raise code size greatly.




