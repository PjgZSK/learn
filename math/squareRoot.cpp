/*************************************************************************
    > File Name: squareRoot.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/10/21 8:56:20
 ************************************************************************/

#include "squareRoot.h"
#include <corecrt_math.h>
#include <cstdlib>

const float PREC = 0.0000001;

float squareRoot(float v, const SRImplemention& implemention)
{
    switch (implemention)
    {
        case SRImplemention::eMidSearch:
            return squareRootMid(v);
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
    } while (fabsf(mid - last) > PREC);
    return mid;
}
