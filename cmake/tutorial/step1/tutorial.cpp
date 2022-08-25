/*************************************************************************
    > File Name: tutorial.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 四  8/25 22:29:23 2022
 ************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cmath>

int main (int argc, char** argv)
{
    if (argc < 2) 
    {
        std::cout << "please input a number !\n";
        return 0;
    }
    int num = std::atoi(argv[1]);
    std::cout << "the square root of " << num << " is " << std::sqrt(num) << "\n";
    return 0;
}
