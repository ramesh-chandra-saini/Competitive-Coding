#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fastExpo(ll N,ll expo,ll mod,ll ans = 1LL){
    for(;expo;expo/=2LL,N=(N*N)%mod)
        ans = (expo%2)?(ans*N)%mod:ans;
    return ans;
}
int main(){
    ll T; scanf("%lld",&T);
    while(T--){
        ll A,N,M; scanf("%lld%lld%lld",&A,&N,&M);
        ll d=0,temp=A;
        do d++,temp/=10LL;
        while(temp);
        ll ans = 0LL;
        for(ll n=0LL,expo=n;n<N;n++,expo+=d)
            ans=(ans+fastExpo(10LL,expo,M))%M;
        ans = (A*ans)%M;
        printf("%lld\n",ans);
    }
    return 0;
}
