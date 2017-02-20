#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<set> edge(n+1);
        while(m--){
            int u,v; cin >> u >> v;
            edge[u].insert(v);edge[v].insert(u);
        }
        set<pair<int,vector<set> > > masterSet;
        for(int i=0;i<m;i++) masterSet.insert(make_pair(edge[i].size(),edge[i]));
        int ans=0;
        while(!masterSet.empty()){
            pair<int,vector<set> > curr = *masterSet.begin();
            for(int i=0;i<curr.first;i++){
                for(int j=0;j<m;j++){
                    if(edge[j].find(curr.second[i])!=edge.end()){

                        edge[j].erase(curr.second[i])
                        }
                }

            }
        }
    }
    return 0;
}
