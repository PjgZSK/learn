/*************************************************************************
    > File Name: test.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 四  8/11 18:39:49 2022
 ************************************************************************/

#include <iostream>
#include <ostream>
using namespace std;

class Concrete1
{
    public:
        int64_t val;
        char bit1;
};

class Concrete2 : public Concrete1
{
    public:
        char bit2;
};

class Concrete3 : public Concrete2
{
    public:
        char bit3;
};

class Concrete4 : public Concrete3
{
    public:
        char bit4;
};

class S
{
    int i;
    int j;
    int k;
};

int main(int argc, char * argv[])
{
    Concrete3 c1, c2;
    Concrete2 *p1 = &c1, *p2 = &c2;
    c2.bit3 = 'a';
    *p1 = *p2;
    cout << sizeof(Concrete1) << "\n"
        << sizeof(Concrete2) << "\n"
        << sizeof(Concrete3) << "\n"
        << sizeof(Concrete4) << "\n"
        << c1.bit3 << "\n";
    return 0;
}
