#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<ll,ll>,ll> dp;
int main() {
    ll n; cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++){
            cin >> arr[i];
        for(ll d=-100;d<=100;d++)
                dp[make_pair(arr[i],d)]=1+dp[make_pair(arr[i]-d,d)];

    }
    for(map<pair<ll,ll>,ll> ::iterator it = dp.begin();it!=dp.end();++it)
        if(it->second>1)
        cout<<it->first.first<<" "<<it->first.second<<" : "<<it->second<<endl;
    return 0;
}
