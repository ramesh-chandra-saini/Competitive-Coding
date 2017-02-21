#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getDist(pair<ll,ll>&A,pair<ll,ll>&B){
    return (A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second);
}
ll getParameter(vector<pair<ll,ll> > &Geo,pair<ll,ll>Point){
    ll ans=0LL,n=Geo.size();
    for(ll i=0;i<n;i++)
            ans = max(ans,getDist(Geo[i],Point));
    return ans;
}
int main(){
    ll n;cin >> n;
    vector<pair<ll,ll> > Geo;
    ll ans = 0LL;
    for(ll i=0,x,y;i<n;i++){
        cin >> x >> y;
        Geo.push_back(make_pair(x,y));
        ans=max(ans,getParameter(Geo,make_pair(x,y)));
        cout<<ans<<endl;
    }
}
