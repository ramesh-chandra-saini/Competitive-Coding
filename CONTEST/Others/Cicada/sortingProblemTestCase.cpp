#include<bits/stdc++.h>
#include <random>
#include <iostream>
using namespace std;
#define ll long long int
#define maxN  100000
#define maxAi 1000000000000000000
#define modAi 1000000000000000
int main(){
    srand(time(NULL));

    ll T = 10;
    printf("%lld\n",T);
    while(T--){
        ll N; N = 90000+rand()%(maxN-90000);
        printf("%lld\n",N);
        const ll range_from  = -maxAi;
        const ll range_to    = maxAi;
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<ll>  distr(range_from, range_to);


        for(ll i=1;i<=N;i++){
            ll Ai =  distr(generator) ;
             if(Ai>=-modAi && Ai<=modAi){
                --i;
                continue;
            }
              printf("%lld ",Ai);
        }
        printf("\n");
    }
    return 0;
}
