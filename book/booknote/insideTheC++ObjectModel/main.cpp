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

int main(int argc, char * argv[])
{
    std::cout << "sizeof: \n";
    std::cout << "A : " << sizeof(A) << "\n";
    std::cout << "B : " << sizeof(B) << "\n";
    std::cout << "C : " << sizeof(C) << "\n";
    std::cout << "D : " << sizeof(D) << "\n";
    std::cout << "Concretel1 : " << sizeof(Concretel1) << "\n";
    std::cout << "Concretel2 : " << sizeof(Concretel2) << "\n";
    std::cout << "Concretel3 : " << sizeof(Concretel3) << "\n";
    printf("%p\n", &Point3d::x);
    printf("%p\n", &Point3d::y);
    printf("%p\n", &Point3d::z);
    return 0;
}
