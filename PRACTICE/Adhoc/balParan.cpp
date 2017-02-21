#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll ans = 0;
void solve(ll N,ll OC,ll prev,ll ct,ll K,ll hack){
    if(OC>hack)
        return;
    if(OC<0) return;
    if(N==0){
         ans=(ans+(OC==0 && ct>=K))%mod;
        return;
    }
    solve(N-1,OC++,0,ct+=(prev!=0),K);
    solve(N-1,OC--,1,ct+=(prev!=1),K);
}
int main(){
    ll q; cin >> q ; while(q--){
        ll n,k; cin >> n >> k;
        if(n%2){
            cout<<"0"<<endl;
        }else{
            ans=0;
            solve(n,0,0,0,k,n/2);
            cout<<ans<<endl;
        }
    } return 0;
}
