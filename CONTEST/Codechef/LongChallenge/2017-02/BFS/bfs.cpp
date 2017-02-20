#include<bits/stdc++.h>
using namespace std;
int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<vector<int> > adj(N+1,vector<int>());
        for(int i=1,u,v;i<=N-1;i++)
            cin >> u >> v,
            adj[u].push_back(v),
            adj[v].push_back(u);
        int g,k; cin >> g >> k;
        int U[g],V[g];
        for(int i=0;i<g;i++)
            cin >> U[i] >> V[i];
        int ans = 0;
        for(int i=1;i<=N;i++){
            vector<int> parent(N+1,-1);
            vector<int> visited(N+1,false);
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int curr = q.front(); q.pop();
                for(int j=0;j<adj[curr].size();j++){
                    int next = adj[curr][j];
                    if(!visited[next])
                        visited[next] = true,
                        parent[next]=curr,
                        q.push(next);
                }
            }
            int correct_guess = 0;
            //cout<<i<<endl;
            for(int j=0;j<g;j++)
               // cout<<U[j]<<" "<<parent[V[j]]<<endl,
                correct_guess+=(parent[V[j]]==U[j]);
            ans+=(correct_guess>=k);
        }
        if(ans==0){
            cout<<"0"<<endl;
        }else{
            int gcd = __gcd(ans,N);
            cout<<(ans/gcd)<<"/"<<(N/gcd)<<endl;
        }
    }
    return 0;
}
