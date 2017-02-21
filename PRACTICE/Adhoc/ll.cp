#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp(N,OC,prev) make_pair(make_pair(N,make_pair(OC,prev)))
ll ans = 0;
ll count(ll ct,ll prev,ll curr){
    return ct+=prev!=curr;
}
pair<pair<ll,pair<ll,ll> > key;
void solve(ll N,ll OC,ll prev,ll ct,ll K,ll hack,map<pair<pair<ll,pair<ll,ll> >,ll> &mp){
    key=mp(N,OC,prev);
    if(OC>hack)//not leading to valid paranthesis
        return;
    if(OC<0) return;//invalide paranthesis
    if(N==0){ //you are over with number of open/close bracker
        cout<<OC<<" "<<K<<endl;
        if(OC==0 && ct>=K)
            ans++; return;
    }
    if(mp.find)
    //solve for rest of possibilities
    solve(N-1,OC+1,0,count(ct,prev,0),K,hack);
    solve(N-1,OC-1,1,count(ct,prev,1),K,hack);
}
int main(){
    ll q; cin >> q ; while(q--){
       //map<pair<pair<N,pair<OC,prev> >,value>
        map<pair<pair<ll,pair<ll,ll> >,ll> mp;
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
