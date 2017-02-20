#include<bits/stdc++.h>
using namespace std;
/*
///constratins for 10 pts
#define T 100
#define N 1000
#define Q 1000
#define Ai 1000000
*/

///constratins for 100 pts
#define T 100
#define N 100000
#define Q 100000
#define Ai 1000000

#define ll long long int
int main(){
    srand(time(NULL));
    ll t=1+rand()%T; printf("%lld\n",t);
    while(t--){
        ll n = 1+rand()%N;
        ll q = 1+rand()%Q;
        printf("%lld %lld\n",n,q);
        for(ll i=0;i<n;i++)
            printf("%lld ",(1LL+rand()%Ai));
        while(q--){
            ll choice = rand()%2;
            ll L = 1+rand()%n;
            ll R = 1+rand()%n;
            if(L>R){
                swap(L,R);
            }
            printf("%lld %lld %lld\n",choice,L,R);
        }
    }
}
