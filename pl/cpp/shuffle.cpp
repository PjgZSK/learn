/*************************************************************************
    > File Name: shuffle.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2023/3/3 15:48:23
 ************************************************************************/
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <algorithm>
#include <random>

/*
 * engine
 * produce random number 
 * init : seed 
 * loop : get random number and state advance,
 */

/*
 * distribution
 * produce random number, distrubuted on a closed interval in some regular
 * init : interval
 * get a random number by a engine 
 */

/*
 * rand device
 * engine that produce a uniformly-distributed integer random number
 */

/*
 * std::random_shuffle is deprecated in c14 and removed in c17
 * use std::shuffle to replace std::random_shuffle, std::shuffle availiable in c11
 * std::shuffle need a engine parameter
 */

/*
 * reference : https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
 */

int main() {
    std::vector<int> vec{0,1,2,3,4,5};
    std::random_shuffle(vec.begin(), vec.end(), [](int n){return 0;});

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    std::shuffle(vec.begin(), vec.end(), std::default_random_engine((int)1));
    return 0;
}
