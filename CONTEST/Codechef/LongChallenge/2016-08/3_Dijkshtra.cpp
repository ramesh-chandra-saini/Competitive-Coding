/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
#define INT_MAX (1LL<<62)
#define ll long long int

void Dikshtra(vector<vector<ll> >&graph,map<pair<ll,ll>,ll >&visit,map<pair<ll,ll>,ll >&weight,set<pair<ll,ll> >&currNodes,vector<ll>&dist){
    if(currNodes.empty()) return;
    ll currNode=currNodes.begin()->second;
    currNodes.erase(currNodes.begin());
    for(ll i=0LL;i<graph[currNode].size();i++){
        ll neighbour=graph[currNode][i];
        if(visit[make_pair(currNode,neighbour)]<2LL){
            dist[neighbour]=min(dist[neighbour],dist[currNode]+weight[make_pair(currNode,neighbour)]);
            visit[make_pair(currNode,neighbour)]++,visit[make_pair(neighbour,currNode)]++;
            currNodes.insert(make_pair(weight[make_pair(currNode,neighbour)],neighbour));
        }
    } Dikshtra(graph,visit,weight,currNodes,dist);
}
int main(){
    ll t; cin >> t; while(t--){
        ll n; cin >> n;
        vector<vector<ll> >graph(n+1LL,vector<ll>());
        map<pair<ll,ll>,ll > visit,weight;
        for(ll i=1LL,x,y,w;i<=n;i++) {
            x=i,y=(i%n)+1LL,cin>>w;
            weight[make_pair(x,y)]=weight[make_pair(y,x)]=w;
            visit [make_pair(x,y)]=visit [make_pair(y,x)]=0LL;
            graph[x].push_back(y),graph[y].push_back(x);
        }
        ll source,destination; cin >> source >> destination;
        vector<ll> dist(n+1LL,INT_MAX);
        set<pair<ll,ll> > currNodes;
        dist[source]=0LL;currNodes.insert(make_pair(0LL,source));
        Dikshtra(graph,visit,weight,currNodes,dist);
        cout<<dist[destination]<<endl;
    }return 0LL;
}
