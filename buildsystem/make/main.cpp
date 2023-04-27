/*************************************************************************
    > File Name: main.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 四  7/28 19:20:46 2022
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include "numeric.h"

int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        std::cout << "please input at least 2 integer\n";
        return 0;
    }

    std::cout << "start----------------------------\n";
    
    std::cout << argv[1] << " and " << argv[2] << "'s\n";
    auto num1 = atoi(argv[1]);
    auto num2 = atoi(argv[2]);
    std::cout << "gcd is " << gcd(num1, num2);
    std::cout << " and lcm is " << lcm(num1, num2);
    std::cout << "\n";

    std::cout << "end----------------------------\n";
    return 0;
}
