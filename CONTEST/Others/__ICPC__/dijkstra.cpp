#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
int main(){
    int t; cin >> t; while(t--){
        int n,m,u,v; cin >> n >> m ;
        vector<vector<pair<int,int> > >graph(n+1,vector<pair<int,int> >());
        while(m--){
            cin >> u >> v;
            graph[u].push_back(make_pair(v,6));
            graph[v].push_back(make_pair(u,6));
        }
        vector<int> dist(n+1,INF);
        int start; cin >> start;
        set<pair<int,int> > nodes; nodes.clear();
        nodes.insert(make_pair(0,start));
        dist[start]=0;
        while(!nodes.empty()){
            int curr = nodes.begin()->second;
            nodes.erase(nodes.begin());
            for(int i=0;i<graph[curr].size();i++){
                int next = graph[curr][i].first;
                int weight = graph[curr][i].second;
                if(dist[next]>dist[curr]+weight){
                    if(dist[next]!=INF)
                        nodes.erase(make_pair(dist[next],next));
                    dist[next] = dist[curr]+weight;
                    nodes.insert(make_pair(dist[next],next));
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(i==start) continue;
            (dist[i]==INF)?cout<<"-1"<<" ":cout<<dist[i]<<" ";
        } cout<<endl;
    }   return 0;
}
