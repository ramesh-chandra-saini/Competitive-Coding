#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans = 1;
int main() {
    ll n,k; cin >> n >> k;
    vector<ll> mp(k,0LL);
    for(ll i=0,val;i<n;i++)
        cin >> val,mp[(val%k)]++;
    vector<pair<ll,ll> > ds;
    for(ll i=0;i<k;i++)
        if(mp[i]==0)//absent remainder
            continue;
        else
            ds.push_back(i,mp[i]);
    ll ans = 1;
    for(int i=0;i<ds.size();i++)
        ans = max(ans,solve(ds[i].size()-1, ds[i].first,))

    for(ll i=0;i<k;i++){
        if(mp[i]==0)//absent remainder
            continue;
        ll curr = 0;
        for(ll j=0;j<k;j++){
              if(mp[j]==0)//absent remainder
                continue;
            if( (i+j)%k==0)
                continue;
            curr+=mp[j];
        }
       // cout<<curr<<" ";
        ans = max(ans,curr);
    }
    cout<<ans<<endl;
    return 0;
}
