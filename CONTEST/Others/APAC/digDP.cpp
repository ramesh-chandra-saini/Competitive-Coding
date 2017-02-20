#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define KEY pair<ll,pair<ll,ll> >
#define make_key(N,OC,prev) make_pair(N,make_pair(OC,prev))
ll ans = 0;
ll fun(ll ct,ll prev,ll curr){//author function
    return ct+=(prev!=curr);
}
map<KEY,ll> dp;
ll solve(ll N,ll OC,ll prev,ll ct,ll K,ll hack){
    if(OC>N)//not leading to valid paranthesis
        return 0LL;
    if(OC<0) return 0LL;//invalide paranthesis
    if(N==0){ //you are over with number of open/close bracket, check validity
        //cout<<OC<<" "<<K<<endl;
        if(OC==0 && ct>=K)
            return 1LL;
        return 0LL;
    }
    KEY key = make_key(N,OC,prev);
    if(dp.find(key)!=dp.end())
        return dp[key];
    //
    return dp[key]=(solve(N-1,OC+1,0,ct+(prev!=0),K,hack)+solve(N-1,OC-1,1,ct+(prev!=1),K,hack))%mod;
}
int main(){
    ll q; cin >> q ; while(q--){
        dp.clear();
        ll n,k; cin >> n >> k;
        if(n%2){
            cout<<"0"<<endl;
        }else{
            cout<<solve(n,0,0,0,k,n/2)<<endl;
        }
    } return 0;
}
