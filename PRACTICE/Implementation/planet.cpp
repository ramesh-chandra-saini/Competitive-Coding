#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        set<ll> pset;pset.clear();
        map<ll,ll>pmap;pmap.clear();
        vector<ll> P(n+1,0);
        for(int i=1;i<=n;i++)
            cin >> P[i],pset.insert(-P[i]),pmap[P[i]]=i;
        vector<vector<ll > > adj(n+1,vector<ll>());
        for(int i=1;i<=n;i++) //push itself
            adj[i].push_back(i);
        for(int i=1;i<=n-1;i++){
            ll u,v; cin >> u  >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<adj[i].size();j++){
                pset.erase(-P[adj[i][j]]);
            }
            if(pset.empty())
                cout<<"0"<<" ";
            else
                cout<<pmap[-(*pset.begin())]<<" ";
            for(int j=0;j<adj[i].size();j++){
                pset.insert(-P[adj[i][j]]);
            }
        }
        cout<<endl;
    }
    return 0;
}
