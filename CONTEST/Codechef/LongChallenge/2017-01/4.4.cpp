#include<bits/stdc++.h>
using namespace std;
void dfs(int curr,vector<multiset<int> > &adj,vector<bool> &visited){
    if(visited[curr])  return;
    visited[curr] = true;
    for(multiset<int>::iterator i=adj[curr].begin();i!=adj[curr].end();++i)
        dfs(*i,adj,visited);
}
int main(){
    int N,E; cin >> N >> E;
    vector<multiset<int> > adj(N+1,multiset<int>());
    vector<pair<int,int> > edges(E);
    for(int i=0;i<E;i++){
        int u,v; cin >> u >> v;
        edges[i]=(make_pair(u,v));
        adj[u].insert(v);
        adj[v].insert(u);
    }
    bool flag = true;
    multiset<int> holder;
    for(int i=1;i<=N;i++){
        holder.insert(i);
        flag = (adj[i].empty()==true || adj[i].size()%2==1)?false:flag;
    }
    if(!flag) printf("NO\n");
    else{
        vector<multiset<int> > ans(N+1,multiset<int>());
        int curr = 1;   holder.erase(1);
        while(true){
            if(adj[curr].empty()){
                if(holder.empty()) break;
                else curr = *holder.begin(), holder.erase(curr);
            }else{
                int next = *adj[curr].begin();
                ans[curr].insert(next);
                adj[curr].erase(adj[curr].find(next));
                adj[next].erase(adj[next].find(curr));
                curr = next;
            }
        }
        vector<bool>visited(N+1,false);
        dfs(1,ans,visited);
        for(int i=1;i<=N;i++)
            flag &=visited[i];
        if(!flag)
            printf("NO\n");
        else{
            printf("YES\n");
            for(int i=0;i<edges.size();i++){
                int curr = edges[i].first;
                int next = edges[i].second;
                if(ans[curr].find(next)!=ans[curr].end())
                    printf("%d %d\n",curr,next);
                else printf("%d %d\n",next,curr);
            }
        }
    }
    return 0;
}
