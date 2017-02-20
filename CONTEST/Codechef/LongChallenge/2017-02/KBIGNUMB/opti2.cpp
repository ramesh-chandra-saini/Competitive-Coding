#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fastExpo(ll N,ll expo,ll mod,ll ans = 1LL){
    for(;expo;expo/=2LL,N=(N*N)%mod)
        ans = (expo%2)?(ans*N)%mod:ans;
    return ans;
}
ll phi(ll M){
    map<ll,ll> pf;
    ll __M__ = M,phi_M = 1LL;
    for(ll i=2LL;i*i<=M;i++)
        while(M%i==0)
            ++pf[i],M/=i;
    if(M>1) ++pf[M];//if any prime left
    for(map<ll,ll> ::iterator it=pf.begin();it!=pf.end();it++)
        phi_M*=(pow(it->first,it->second)-pow(it->first,it->second-1LL));
    return phi_M;//Ajinkya ==> phi(M)-1
}
int main(){
    ll T; scanf("%lld",&T);
    while(T--){
        ll A,N,M; scanf("%lld%lld%lld",&A,&N,&M);
        if(A==0){
            printf("%lld\n",0);
            continue;
        }
        ll r = 1LL; while(r*10LL<=A) r*=10LL;
        ll p = (M+fastExpo(r,N,M)-1)%M;
        ll q = r-1;
        ll ans = (p*fastExpo(q,phi(M)-1LL,M))%M;
        printf("%lld\n",ans);
    }
    return 0;
}
