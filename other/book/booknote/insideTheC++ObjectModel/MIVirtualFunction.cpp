/*************************************************************************
    > File Name: MIVirtualFunction.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/8/16 16:28:04
 ************************************************************************/
#include <cstdio>
#include <iostream>
#include <new>
#include <ostream>
//#include <new>

class Base1
{
public:
    Base1() {}
    virtual ~Base1() {  std::cout << "class base1 destructor called !\n"; }
    virtual void base1VF() { std::cout << "class base1 vf called !\n"; }
    virtual Base1* clone() {  std::cout << "class base1 clone called !\n"; return new (std::nothrow) Base1(); }
private:
    float data_Base1;
};

class Base2
{
public:
    Base2() {}
    virtual ~Base2() { std::cout << "class base2 destructor called !\n"; }
    virtual void base2VF() { std::cout << "class base2 vf called !\n";}
    virtual Base2* clone() { std::cout << "class base2 clone called !\n"; return new (std::nothrow) Base2(); }
private:
    float data_Base2;
};

class Derived : public Base1, public Base2
{
public:
    Derived() {}
    virtual ~Derived() { std::cout << "class derived destructor called !\n"; }
    virtual Derived* clone() { std::cout << "class derived clone called !\n"; return new (std::nothrow) Derived(); }
private:
    float data_Derived;
};

class TestClass
{
public:
    TestClass() {}
    virtual void f() { std::cout << "f() called !\n"; }
    virtual void d() { std::cout << "d() called !\n"; }
    virtual void b() { std::cout << "b() called !\n"; }
    void nonvfunc(){ }
};

typedef void(*Func)();

int main(int argc, char* argv[])
{
    auto pd = new (std::nothrow) Derived();
    Base1* pb1 = pd;
    Base2* pb2 = pd; 
    printf("Derived Address is : %p\n", pd); 
    printf("Base1 Address is : %p\n", pb1); 
    printf("Base2 Address is : %p\n", pb2); 
    printf("Derived Size is : %llu\n", sizeof(Derived)); 
    printf("Base1 Size is : %llu\n", sizeof(Base1)); 
    printf("Base2 Size is : %llu\n", sizeof(Base2));

    TestClass t;

    /* compiler : g++
     * version : g++ (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0
     */

    ((Func)*((unsigned long long*)*(unsigned long long*)(&t) + 0))();//f()
    ((Func)*((unsigned long long*)*(unsigned long long*)(&t) + 1))();//d()
    ((Func)*((unsigned long long*)*(unsigned long long*)(&t) + 2))();//b()
    
    //((Func)*((unsigned long long*)*(unsigned long long*)(pb2) + 2))();//base2VF
    //((Func)*((unsigned long long*)*(unsigned long long*)(pd) + 2))();//base1VF
    //((Func)*((unsigned long long*)*(unsigned long long*)(pd) + 3))();//derived clone
    //((Func)*((unsigned long long*)*(unsigned long long*)(pd) + unknow))();//base2VF
    //((Func)*((unsigned long long*)*(unsigned long long*)(pd) + 0))();//destructor
    return 0;
}
