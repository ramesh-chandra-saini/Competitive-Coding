#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,s; cin >> n >> m >> k >> s;
    int w[n+1]; for(int i=1;i<=n;i++) cin >> w[i];
    vector<vector<int> > graph(n+1,vector<int>());
    while(m--){
        int u,v; cin >> u >> v;
        graph[u].push_back(v),graph[v].push_back(u);
    }
    vector<int> ans; ans.clear();
    for(int i=0;i<k;i++) cout<<(1+((2*i)%n))<<" "; cout<<endl;
    return 0;
}
