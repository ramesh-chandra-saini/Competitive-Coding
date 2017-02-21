// g++ -std=c++0x -o cxx12_random sortingProblemTestCase.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define maxN 100000

int main(){
    srand(time(NULL));
    ll T = 25;
    printf("%lld\n",T);
    while(T--){
        ll N; N = 1+rand()%maxN;
        printf("%lld\n",N);
        for(ll i=1;i<=N;i++){
            ll Ai =  rand()%2 ;
              printf("%lld ",Ai);
        }
        printf("\n");
    }
    return 0;
}
