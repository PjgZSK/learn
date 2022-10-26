/*************************************************************************
    > File Name: main.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/10/21 9:45:55
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include "squareRoot.h"

int main(int argc, char * argv[])
{
    std::vector<float> fvec{ 0.999, 2.3345, 0.234 , 345 , 4 , 64 , 1889, 565656 };
    for (auto f : fvec)
    {
        auto ms = squareRoot(f, SRImplemention::eMidSearch);
        auto nt = squareRoot(f, SRImplemention::eNewton);
        auto fi = squareRoot(f, SRImplemention::eFastInverse);
        printf("value %f 's square root is :\n %f [midsearch]\n %f [newton]\n %f [fast inverse]\n\n", f, ms, nt, fi);
    }
    return 0;
}
