# the c++ object model
## 1. class members
* data members
    > static  
    > nonstatic

* function members
    > static  
    > nonstatic  
    > virtual
## 2. object model
* a simple object model
    > class object is slot collection, every slot point to a class member

* a table-driven object model
    > class object only has two slot : **data member slot** and **function member slot**.  
    > **data member slot** point to a *data member table*  
    > **function member slot** point to a *function member table*  
    > *data member table* contain data directly  
    > *function member table* contain slots which point to member function

* the c++ object model
    > static data members and function members is out of class object  
    > class object contain nonstatic data members directly  
    > if has virtual function, class object contain a **vptr**(virtual table pointer) which point to a **vtbl**(virtual table)  
    > **vtbl** contain all virtual function pointers which this class object has and object type info  
    > **vptr** usually in class object first address or last address for efficiency
## 3. the c++ object model with inheritance
* simple inheritance
    > **vptr** point correctly guaranteed by *constructor*, *destructor* and *copy* function(of course compiler will add code automatic).  
    > simple inheritance : nonstatic data member will inherited by derived class directly

* virtual inheritance
    > the base class inherited with virtual called virtual base class  
    > the virtual base class only has one data at its all derived class  
    > for this, derived class dont contain the virtual base class's nonstatic data members directly instead of contain a pointer pointed to the base class  
    > the location of the pointer pointed to the virtual base class defined by class type owend it   
    > use `public/protected/private virtual` for virtual inheritance   
    
    > test code
    > ```
    > class A {};  
    > class B : public virtual A {};
    > class C : public virtual A {};
    > class D : public B, public C {};
    >```
    > can you tell the bytes of A, B, C and D ?  
    > you can use `sizeof` check your answer.


## 4. alignment
* rules
    > 1. for memory access efficiency, every nonstatic basic type data member will not cross 2 address.  
    > 2. the total bytes of class will be n multiple bytes which is max bytes with all basic type contained by the class.  
    > 3. the empty class object will inserted 1 byte for get a address in memory.

* test code
    > ```
    > struct S
    > {
    >    int i;//4
    >    short j;//2 + 2(padding)
    >    double k;//8
    >    int l;//4 + 4(padding)
    > };
    > ```
    > the result of `sizeof(S)` is 24

   
## 5. problem caused by alignment
* padding expand in inheritance.
    > consider blow code  
    > ```
    > class Point { int i; char x; };
    > class Point2d { char y; };
    > class Point3d { char z; };
    > ```
    > can you tell the bytes of `Point`, `Point2d` and `Point3d` ?  
    > in 64 bit compiler, `Point` is 8 bytes, `Point2d` is 12 bytes and `Point3d` is 16 bytes  

    > why ? why compiler dont optimize the layout of `Point2d` and `Point3d` ?  
    > consider blow code  
    > ```
    > Point2d d2, d3;
    > Point *d2p = d2;
    > *d2p = d3;
    > ```
    > if `d3.y != d2.y`, what will happen on `d2` with the optimization of layout ?  
    > the answer is will cause logic error becase of  `d2.y` will covered by `d3.y`

    > but the bytes determined by compiler.  
    > in `g++ (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0`, result will be 8, 12, 12.  
    > in `Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023`, result will be 8, 12, 16.  
    > it seems `g++` optimize the last class, and `msvc` not.

## 6. problem caused by virtual inheritance
* ```
  Point3d origin, &pt = &origin;
  origin.x = .0f;
  pt->x = .0f;
  ```
  there is any difference access `x` by `origin` or `pt` ?  
  only when `Point3d` has a virtual base class and `x` is a member of the virtual base class
    > in this case,  
    > the true class type of `pt` point to cant known in compile time,  
    > so the pointer pointd to the virtual base class cant known in compile time,  
    > so the address of `x` cant known in compile time,  
    > so access by `pt` will delayed in runtime.  
    > and access by `origin` will not.  
    > and access by `pt` will not in other case.
