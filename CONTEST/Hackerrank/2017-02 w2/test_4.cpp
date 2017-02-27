#include<bits/stdc++.h>
#include <random>

#ifndef _CXX0X_WARNING_H
#define _CXX0X_WARNING_H 1

#if __cplusplus < 201103L
#error This file requires compiler and library support for the \
ISO C++ 2011 standard. This support is currently experimental, and must be \
enabled with the -std=c++11 or -std=gnu++11 compiler options.
#endif

#endif


using namespace std;
int main(){

    srand(time(NULL));

    const long long int range_from  =  1;
    const long long int range_to    = 1000000000000000;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<ll>  distr(range_from, range_to);

    long long int first = distr(generator);
    long long int last = first+1000000000;

    printf("%lld %lld\n",first,last);
    return 0;
}
