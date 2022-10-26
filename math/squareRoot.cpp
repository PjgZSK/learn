/*************************************************************************
    > File Name: squareRoot.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/10/21 8:56:20
 ************************************************************************/

#include "squareRoot.h"
#include <corecrt_math.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>

const float PREC = 0.0000001;

float squareRoot(float v, const SRImplemention& implemention)
{
    switch (implemention)
    {
        case SRImplemention::eMidSearch:
            return squareRootMid(v);
        case SRImplemention::eNewton:
            return squareRootNewton(v);
        case SRImplemention::eFastInverse:
            return squareRootFastInv(v);

        default:
            break;
    }
    return -1;
}

float squareRootMid(float v)
{
    auto l = v < 1 ? v : 0.0f;
    auto r = v < 1 ? 1.0f : v;
    float mid = (l + r) / 2;
    float last;
    int times = 0;
    do
    {
        if (mid * mid > v)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }

        last = mid;
        mid = (l + r) / 2;
        ++times;
    } while (fabsf(mid - last) > PREC);
    printf("calc times is %d [midsearch]\n", times);
    return mid;
}

float squareRootNewton(float x)
{
    int temp = (((*(int*)(&x))&0xff7fffff)>>1)+(64<<23);
    auto val = *(float*)&temp;
    //auto val = x / 2;
    auto last = val;
    int times = 0;
    do
    {
        last = val;
        val = (val + x / val) / 2;
        ++times;
    } while (fabsf(last - val) > PREC);
    printf("calc times is %d [newton]\n", times);
    return val;
}

float squareRootFastInv(float number)
{
    int i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(int *)&y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );
    y  = y * ( threehalfs - ( x2 * y * y ) );
    //return 1 / y;
    return y * number;
}
