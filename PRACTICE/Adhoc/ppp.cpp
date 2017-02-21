#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll fast(ll N,ll pw,ll ans=1LL){
    for(;pw;N=(N*N)%mod,pw/=2LL)
        ans=(pw%2)?((N*ans)%mod):(ans%mod);
    return ans;
}
int main(){
    ll t; cin >> t;while(t--){
        ll n; cin >> n;
        ll ans = (n<2LL)?0LL:((mod+fast(2LL,n-1LL)-2LL)%mod);
        cout<<ans<<endl;
    }
}
