#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,E; cin >> N >> E;
    vector<multiset<int> > ADJ(N+1,multiset<int>());
    vector<pair<int,int> > edges;
    set<int> holder;
    for(int i=1;i<=N;i++){
        holder.insert(i);
    }

    vector<vector<int> > adj(N+1,vector<int>());

    for(int i=0;i<E;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    //print(N,ADJ);
    bool flag = true;
     for(int i=0;i<N;i++){
        flag = (adj[i].empty() || adj[i].size()%2==1)?false:flag;
    }

    vector<multiset<int> > ans(N+1,multiset<int>());
    if(flag==false){
        printf("NO\n");
    }else{
        printf("YES\n");

    }
    return 0;
}
