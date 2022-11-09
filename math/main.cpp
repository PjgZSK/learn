/*************************************************************************
    > File Name: main.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/10/21 9:45:55
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "squareRoot.h"
#include "pythagorean.h"

void testSquareRoot()
{
    std::vector<float> fvec{ 0.999, 2.3345, 0.234 , 345 , 4 , 64 , 1889, 565656 };
    for (auto f : fvec)
    {
        auto ms = squareRoot(f, SRImplemention::eMidSearch);
        auto nt = squareRoot(f, SRImplemention::eNewton);
        auto fi = squareRoot(f, SRImplemention::eFastInverse);
        printf("value %f 's square root is :\n %f [midsearch]\n %f [newton]\n %f [fast inverse]\n\n", f, ms, nt, fi);
    }
}

void testPythagorean()
{
    using namespace pythagorean;
    std::vector<Pitch> pitchs;
    Pitch upPitch(Fraction(1));
    Pitch downPitch(Fraction(1));
    pitchs.push_back(upPitch);
    for (int i = 0; i < 5; ++i)
    {
        upPitch.nextUp();
        downPitch.nextDown();
        //printPitch(downPitch);
        pitchs.push_back(upPitch);
        pitchs.push_back(downPitch);
    }
    //printf("\n");
    std::sort(pitchs.begin(), pitchs.end(), [](const Pitch& l, const Pitch& r) {
        return l.value < r.value;
    });

    for (auto& pitch : pitchs)
    {
        printPitch(pitch);        
    }
}

int main(int argc, char * argv[])
{
    testPythagorean();
    return 0;
}
