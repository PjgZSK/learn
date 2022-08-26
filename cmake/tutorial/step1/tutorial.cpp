/*************************************************************************
    > File Name: tutorial.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 四  8/25 22:29:23 2022
 ************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "TutorialConfig.h"

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
    std::cout << "the square root of " << num << " is " << std::sqrt(num) << "\n";
    return 0;
}
