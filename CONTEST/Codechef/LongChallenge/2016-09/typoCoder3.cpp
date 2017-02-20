#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll solve(ll A, ll B){
    ll ans=1LL;
    ll expo= mod-2;
    for(;expo;B=(B*B)%mod, expo>>=1){
        (expo&1LL)?ans=(ans*B)%mod:ans=ans;
    }
    return(A*ans)%mod;
}
int main(){
    ll n; cin >> n;
    ll arr[n+1]; for(ll i=1;i<=n;i++) cin >> arr[i];
    ll mult[n+1]; mult[0]=1LL;
    for(ll i=1;i<=n;i++)
        mult[i]=(mult[i-1]*arr[i])%mod;
    ll q; cin >> q; while(q--){
        ll l,r; cin >> l >> r;
        ll R=mult[r];
        ll L=mult[l-1];
        cout<<solve(R,L)<<endl;
    }return 0;
}
