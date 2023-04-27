/*************************************************************************
    > File Name: tutorial.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 四  8/25 22:29:23 2022
 ************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <chrono>
#include "TutorialConfig.h"


#ifdef USE_MYMATH
    #include "MathFunctions.h"
#endif

int main (int argc, char** argv)
{
    if (argc < 2) 
    {
        //report version
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "please input a number !\n";
        return 1;
    }
    double num = std::atof(argv[1]);
    auto stime = std::chrono::steady_clock::now();    
#ifdef USE_MYMATH
    double val = mysqrt(num); 
#else
    double val = std::sqrt(num); 
#endif
    auto etime = std::chrono::steady_clock::now();
    std::cout << "time is : " << 
        (etime.time_since_epoch().count() - stime.time_since_epoch().count()) << " ns\n"
        << num 
        << " is " << val 
        << "\n";
    return 0;
}
