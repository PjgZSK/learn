/*************************************************************************
    > File Name: numeric.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 二  7/26 21:22:45 2022
 ************************************************************************/
#include "numeric.h"

unsigned gcd(unsigned a, unsigned b)
{
    if (0 == a % b) return b;
    return gcd(b, a % b);
}

unsigned lcm(unsigned a, unsigned b)
{
    return a * b / gcd(a, b);
}
