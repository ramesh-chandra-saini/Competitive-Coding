#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10
#define M 1000000
#define A 100
int main(){
    ll n = 1+rand()%N,m = 1+rand()%M; printf("%lld %lld\n",n,m);
    for(ll i=0;i<n;i++)
        printf("%lld ",rand()%A);
    printf("\n");
    return 0;
}
