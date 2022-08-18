/*************************************************************************
    > File Name: constructionDestructionAndCopy.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/8/18 9:52:03
 ************************************************************************/
#include <cstdio>
#include <iostream>

class Base
{
public:
    Base(){ std::cout << "call Base constructor !\n"; }
    virtual ~Base(){ std::cout << "call Base destructor !\n"; }

protected:
    float base_data;
};

class VDerived1 : public virtual Base
{
public:
    VDerived1() { std::cout << "call VDerived1 constructor !\n"; }
    virtual ~VDerived1() {std::cout << "call VDerived1 destructor !\n"; }
protected:
    float vderived1_data;
};

class Derived;
class VDerived2 : public virtual Base
{
public:
    VDerived2() { std::cout << "call VDerived2 constructor !\n"; }
    VDerived2(Derived* const d); //{ std::cout << "call VDerived2 constructor !\n"; d->func(); }
    virtual ~VDerived2() {std::cout << "call VDerived2 destructor !\n"; }
protected:
    float vderived2_data;
};

class Derived : public VDerived1, public VDerived2
{
public:
    Derived() { std::cout << "call Derived constructor !\n"; 
        //std::printf("vptr : %p\n", (unsigned long long*)*(unsigned long long*)this);
    }
    Derived(bool callVirtual) : VDerived2(this) { std::cout << "call Derived-- constructor !\n";}
    virtual void func() { std::cout << "call Derived func !\n";}
    virtual ~Derived() { std::cout << "call Derived destructor !\n"; 
        //std::printf("vptr : %p\n", (unsigned long long*)*(unsigned long long*)this);
    }
protected:
    float derived_data;
};

VDerived2::VDerived2(Derived* const d) { std::cout << "call VDerived2-- constructor !\n"; 
    std::printf("vptr : %p\n", (unsigned long long*)*(unsigned long long*)d);
    //d->func(); 
}

int main(int argc, char * argv[])
{
    //Derived* pd = new Derived();
    //delete pd;
    Derived dd(0);
    std::printf("vptr : %p\n", (unsigned long long*)*(unsigned long long*)(&dd));
    return 0;
}
