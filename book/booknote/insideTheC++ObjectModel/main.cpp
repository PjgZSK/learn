/*************************************************************************
    > File Name: main.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/8/10 16:55:32
 ************************************************************************/
#include <iostream>
#include <stdint.h>
#include <stdio.h>

class A { };
class B : public virtual A { };
class C : public virtual A { };
class D : public B, public C { };

class Concretel1 { 
public: 
    int val = 1; 
    char bit1; 
};
class Concretel2 : public Concretel1 { 
public:
    char bit2; 
};
class Concretel3 : public Concretel2 { 
public:
    char bit3; 
};

struct S
{
    int i;
    short j;
    double k;
    int l;
};

struct SS
{
    int j;
    int i;
    int k;
};

struct SSS
{
    SS s;
    char c;
    int j;
};

class Point3d
{
public:
    virtual ~Point3d() { }

public:
    float x, y, z;
};

struct Base1 { int val1; };
struct Base2 { int val2; };
struct Derived : Base1, Base2 { int val; };

void func1(int Derived::*dmp, Derived* pd)
{
    std::cout << pd->*dmp << "\n";
}

void func2(Derived* pd)
{
    int Base2::*bmp = &Base2::val2;
    func1(bmp, pd);
}

int main(int argc, char * argv[])
{
    std::cout << "sizeof: \n";
    std::cout << "A : " << sizeof(A) << "\n";
    std::cout << "B : " << sizeof(B) << "\n";
    std::cout << "C : " << sizeof(C) << "\n";
    std::cout << "D : " << sizeof(D) << "\n";
    std::cout << "S : " << sizeof(S) << "\n";
    std::cout << "Concretel1 : " << sizeof(Concretel1) << "\n";
    std::cout << "Concretel2 : " << sizeof(Concretel2) << "\n";
    std::cout << "Concretel3 : " << sizeof(Concretel3) << "\n";
    printf("%p\n", &Point3d::x);
    printf("%p\n", &Point3d::y);
    printf("%p\n", &Point3d::z);

    Derived d;
    d.val1 = 1;
    d.val2 = 2;
    func2(&d);
    printf("&Base1::val1 = %p\n", &Base1::val1);
    printf("&Base2::val2 = %p\n", &Base2::val2);
    printf("&Derived::val1 = %p\n", &Derived::val1);
    printf("&Derived::val2 = %p\n", &Derived::val2);
    printf("&Derived::val = %p\n", &Derived::val);
    return 0;
}
