#include<bits/stdc++.h>
#include <random>
using namespace std;
#define ll long long int
#define maxN 1
//#define maxN  1000000000000001
int main(){
    freopen("in.txt","w",stdout);
    srand(time(NULL));

    const ll range_from  =  1;
    const ll range_to    = maxN;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<ll>  distr(range_from, range_to);

    ll first = distr(generator);
    ll last = first+1000000000;

    printf("%lld %lld\n",first,last);
    return 0;
}
