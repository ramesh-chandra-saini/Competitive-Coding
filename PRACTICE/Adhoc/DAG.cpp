#include<bits/stdc++.h>
using namespace std;
#define ll long long
void DFS(ll curr,vector<vector<ll> >&graph,ll x,vector<ll>&weight,ll lo=0){

    for(ll i=0;i<graph[curr].size();i++){
        ll v = graph[curr][i];
        if(v>lo)
            weight[v]=x;
        DFS(curr,graph,x,weight,lo);
    }
}
int main(){
    ll n,m,q; cin >> n >> m >> q;
    vector<vector<ll> > graph(n+1,vector<ll >());
    while(m--){
        ll u,v; cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<ll> weight(n+1,0);
    while(q--){
        ll type; cin >> type;
        if(type==1){
           ll u,x; cin >> u >> x;
           DFS(u,graph,x,weight);
        }else if(type==2){
        ll u,x; cin >> u >> x;
           DFS(u,graph,x,weight,x);
        }else if(type==3){
            ll u; cin >> u;
            cout<<weight[u]<<endl;
        }
    }
    return 0;
}
