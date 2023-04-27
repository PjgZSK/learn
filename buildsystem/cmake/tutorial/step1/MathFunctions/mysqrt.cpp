/*************************************************************************
    > File Name: mysqrt.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/8/29 9:16:23
 ************************************************************************/

#include <iostream>
#include <chrono>

#define myabs(x) ((x) > 0 ? (x) : (-x))
double mysqrtMidSearch(double d)
{
    double low = d > 1 ? 0 : d;
    double high = d > 1 ? d : 1;

    double mid = (low + high) / 2;
    double diff = mid * mid - d;
    double p = 0.001;

    auto stime = std::chrono::steady_clock::now();    
    int times = 1;
    while (myabs(diff) > p)
    {
        if (diff > 0)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        mid = (high + low) / 2;
        diff = mid * mid - d;
        ++times;
    }
    auto etime = std::chrono::steady_clock::now();
    std::cout << "calc times is : " << times 
            << "\nprecision is : " << p 
            << std::endl;
    return mid;
}

double mysqrt(double d)
{
    if (d <= 0)
    {
        return 0;
    }
    return mysqrtMidSearch(d);  
}


