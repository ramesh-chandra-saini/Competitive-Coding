#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll power(ll N,ll power,ll mod,ll ans = 1LL){
    for(;power;power/=2LL,N=(N*N)%mod)
        ans = (power%2)?(ans*N)%mod:ans;
    return ans;
}
int main(){
    //freopen("in.txt","r",stdin);
    ll T; scanf("%lld",&T);
    while(T--){
        ll A,N,M; scanf("%lld%lld%lld",&A,&N,&M);
        if(A==0){
            printf("0\n");
        }else{
            ll r = 1LL,ans=1LL,a=A; while(a) r*=10LL,a/=10LL;
            vector<ll> bin; bin.clear();
            while(N) bin.push_back(N),N/=2LL;
            for(ll i=bin.size()-2LL,prev=1LL;i>=0;prev=bin[i],--i){
                ans = ((power(r,prev,M)*ans)%M+ans)%M;
                if(bin[i]%2LL)
                    ans=(ans+power(r,bin[i]-1LL,M))%M;
            }
            printf("%lld\n",(ans*A)%M);
        }
    }
    return 0;
}
