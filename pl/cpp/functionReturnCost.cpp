/*************************************************************************
    > File Name: functionReturnCost.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2023/2/13 10:52:16
 ************************************************************************/

#include <iostream>

using namespace std;

struct A
{
    A()
    {
        cout << "call A construction\n";
    }

    void operator=(const A&)
    {
        cout << "call A copy assignment\n";
    }

    A(A&& a)
    {
        cout << "call A move contruction\n";
    }

    A(const A& a)
    {
        cout << "call A copy construction\n";
    }

    ~A()
    {
        cout << "call A destruction\n";
    }
};

A getA()
{
    A a;
    return a;
}

A getAWithMove()
{
    A a;
    return std::move(a);
}

/*
 * command: g++ functionReturnCost.cpp -o functionReturnCost.exe -std=c++11 -O0 -fno-elide-constructors && ./functionReturnCost.exe
 */

/*
 * 查看寄存器内容（所有，单个）
 * all : :reg
 * single : :reg {register} 
 * 设置和粘贴寄存器内容（命令行模式，编辑模式，普通模式）
 * normal copy and paste: {register}y , {register}p
 * command paste : <Ctrl-R>{register}
 */

int main()
{
    A a;
    cout << "\n*****************begin**************\n";
    cout << "get A without move:\n";
    a = getA();
    cout << "\n\ngetA with move:\n";
    a = getAWithMove();
    cout << "\n****************end****************\n";
    return 0;
}
