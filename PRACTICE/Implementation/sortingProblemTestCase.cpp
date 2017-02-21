#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxT 10 
#define maxN 1000000
#define maxAi 1000000000000000000
int main(){

    ll T = 5;
    printf("%lld\n",T);
    while(T--){
        ll N; N = 1+rand()%maxN;
        printf("%lld\n",N);
        for(ll i=1;i<=N;i++){
            ll Ai = rand()%(2*maxAi)-maxAi;
              printf("%lld ",Ai);
        }
        printf("\n");
    }
    return 0;
}
