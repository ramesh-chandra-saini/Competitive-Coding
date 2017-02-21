#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,E; cin >> N >> E;
    vector<vector<int> > adj(N+1,vector<int>());
    for(int i=1;i<=E;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = true;
    for(int i=1;i<=n;i++){
        flag = (adj[i].size() ==0 || adj[i].size()%2==1)?false:flag;
    }
    if(flag == true){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
   return 0;
}
