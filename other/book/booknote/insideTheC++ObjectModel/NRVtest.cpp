/*************************************************************************
    > File Name: NRVtest.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2022/8/15 11:02:35
 ************************************************************************/
#include <chrono>
#include <iostream>
#include <cstring>

class test
{
    friend test foo(double);
public:
    test() 
    { memset(array, 0, 100 * sizeof(double)); 
    }
    test(const test& t)
    { memcpy(this, &t, sizeof(test)); }
private:
    double array[100];
};

test foo(double val)
{
    test local;
    
    local.array[0] = val;
    local.array[99] = val;

    return local;
}

int main(int argc, char * argv[])
{
    using namespace std::chrono;
    auto starttime = system_clock::now().time_since_epoch().count();
    for (int i = 0; i < 1e7; ++i)
    {
        auto t = foo((double)(i));
    }
    auto endtime = system_clock::now().time_since_epoch().count();
    std::cout << "continue time : " 
        << (float(endtime - starttime) / 100000000) 
        << std::endl;
    return 0;
}
