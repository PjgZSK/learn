/*************************************************************************
    > File Name: MIVirtualFunction.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/8/16 16:28:04
 ************************************************************************/
#include <cstdio>
#include <iostream>
#include <new>
//#include <new>

class Base1
{
public:
    Base1() {}
    virtual ~Base1() {}
    virtual void base1VF() {}
    virtual Base1* clone() const { return new (std::nothrow) Base1(); }
private:
    float data_Base1;
};

class Base2
{
public:
    Base2() {}
    virtual ~Base2() {}
    virtual void base2VF() {}
    virtual Base2* clone() const { return new (std::nothrow) Base2(); }
private:
    float data_Base2;
};

class Derived : public Base1, public Base2
{
public:
    Derived() {}
    virtual ~Derived() {}
    virtual Derived* clone() const { return new (std::nothrow) Derived(); }
private:
    float data_Derived;
};

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
    return 0;
}
