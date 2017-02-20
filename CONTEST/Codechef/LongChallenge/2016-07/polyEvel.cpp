/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
==============================================================
            #BruteForce
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 786433
int main(){

    ll N; scanf("%lld",&N);
    vector<ll> arr(N+1); for(ll i=0;i<=N;i++) scanf("%lld",&arr[i]);
    ll Q; cin >> Q;
    while(Q--){
        ll x; scanf("%lld",&x);
        ll ans=arr[N];//horner's Method
        for(ll i=N-1;i>=0;i--) ans=(ans*x+arr[i])%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
