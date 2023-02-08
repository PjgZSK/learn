/*************************************************************************
    > File Name: testC14.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2023/2/7 9:16:25
 ************************************************************************/

#include <iostream>

template<typename T>
std::enable_if_t<std::is_same_v<T, bool>, T>
test()
{
    return T();
}

int main()
{
    test<bool>();
    return 0;
}
