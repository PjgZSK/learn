/*************************************************************************
    > File Name: pythagorean.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/11/7 11:30:39
 ************************************************************************/
#include "pythagorean.h"
#include <stdio.h>

namespace pythagorean {

void printPitch(const Pitch& p)
{
    printf("%d/%d\t[%f]\n", p.value.nume, p.value.deno, p.value.toFloat());
}

}
