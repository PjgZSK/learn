/*************************************************************************
    > File Name: 20230110.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2023/1/10 10:14:17
 ************************************************************************/

/*
 * 1.setString("x" + std::to_string(count)) 开销
 * 2.lc 1803
 * 3.dailyCreate.sh
 * 4.pragma : pack
 * 5.time
 * 6.memory aligned
 */

#include <cstdio>
#include <cstddef>
#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <chrono>

using namespace std;

namespace memoryAligned
{

    /*
     * 内存模型：
     * 现代计算机从内存中取数据有非常大的限制，比如64位常规计算机，以字节为单位，只能从8的倍数的值开始取数据，每次取8字节。
     * 以下是抽象化的内存模型：
     *      地址    长度
     *      0 * n    n
     *      1 * n    n
     *      ...      ...
     * 计算机每次只能取其中一行数据，对32位计算机来说 n = 4字节，64位 n = 8字节。
     *
     * 内存对齐：
     * 数据在内存中的存放的地址必须是n字节的倍数，这里的n就是对齐值，n的有效取值为1,2,4,8,16
     * n的确定：
     *      选择 #pragma pack（val）和 结构体中最长数据结构的字节数 二者中的小者
     */
//#pragma pack(push, 8)
//#pragma pack(show)
#pragma pack(8)
    struct A
    {
        int a;
        double b;
    };

#pragma pack(4)
    struct B
    {
        int a;
        double b;
    };
    void print()
    {
        printf("sizeof(int) : %lld\n"
                "sizeof(char) : %lld\n"
                "sizeof(short) : %lld\n"
                "sizeof(double) : %lld\n", sizeof(int), sizeof(char), sizeof(short), sizeof(double));
        printf("sizeof(A) : %lld\n", sizeof(A));
        printf("sizeof(B) : %lld\n", sizeof(B));
        printf("%lld ", offsetof(A, a));
        printf("%lld\n", offsetof(A, b));
        printf("%lld ", offsetof(B, a));
        printf("%lld\n", offsetof(B, b));
    }
}

/*
 * 时间定义：
 * 公转产生四季，自转产生一天。（位置变化导致阳光进光量的不同），
 * 地球自转一次就是一天，地球公转一次就是一年；由此定义可推知一年并不一定包含整数个天，也就是说
 *  实际上一年可能有365.4天，因为地球公转结束的时候自转有可能并没有结束。
 * 
 * 
 */

int main(int argc, char ** argv)
{
    memoryAligned::print();
    return 0;
}
