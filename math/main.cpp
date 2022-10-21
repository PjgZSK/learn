/*************************************************************************
    > File Name: main.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/10/21 9:45:55
 ************************************************************************/

#include <iostream>
#include "squareRoot.h"

int main(int argc, char * argv[])
{
    auto v = squareRoot(0.999, SRImplemention::eMidSearch);
    std::cout << v << "\n";
    return 0;
}
