#include<bits/stdc++.h>
using namespace std;

int ans = 0;
map<int,vector<int> > G;
map<int,vector<int> >::iterator it;
void dfs(int curr,vector<bool>&visited,vector<vector<int> > &adj,int correct_guess,vector<int>&parent,int k){

    for(int i=0;i<adj[curr].size();i++){
        int next = adj[curr][i];
        if(!visited[next]){
            visited[next]=true;

            int father = curr;
            int child = next;

            int temp_correct_guess=correct_guess;
            //remove guess count of father
            it = G.find(father);
            if(it!=G.end()){//guessed one
             for(vector<int>::iterator i=it->second.begin();i!=it->second.end();++i)
                temp_correct_guess-=(*i==parent[it->first]);
            }
            //remove guess count of child
            it = G.find(child);
            if(it!=G.end()){//guessed one
             for(vector<int>::iterator i=it->second.begin();i!=it->second.end();++i)
                temp_correct_guess-=(*i==parent[it->first]);
            }

            //change relationship
            parent[father]=child;
            parent[child]=-1;
            //remove guess count of father
            it = G.find(father);
            if(it!=G.end()){//guessed one
             for(vector<int>::iterator i=it->second.begin();i!=it->second.end();++i)
                temp_correct_guess+=(*i==parent[it->first]);
            }
            //remove guess count of child
            it = G.find(child);
            if(it!=G.end()){//guessed one
             for(vector<int>::iterator i=it->second.begin();i!=it->second.end();++i)
                temp_correct_guess+=(*i==parent[it->first]);
            }
            ans+=(temp_correct_guess>=k);
            //go deep
            dfs(next,visited,adj,temp_correct_guess,parent,k);

            //return back relationship
            parent[child]=father;
            parent[father]=-1;


        }


    }
}
int main(){
    //freopen("in.txt","r",stdin);
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
        G.clear();
        //store all guesses
        for(int i=0;i<g;i++)
            G[V[i]].push_back(U[i]);
        //G[i]==0 mean no guess made for ith vertex
        //now run with root = 1

        ans = 0;
        //run bfs once
        vector<int> parent(N+1,-1);
        vector<bool> visited(N+1,false);
        queue<int> q;
        int i = 1;
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
        //compare guess
        for(it = G.begin();it!=G.end();++it)
            for(vector<int>::iterator i=it->second.begin();i!=it->second.end();++i)
                correct_guess+=(*i==parent[it->first]);

        ans+=(correct_guess>=k);
        for(int i=0;i<=N;i++)
            visited[i]=false;
        visited[1]=true;
        dfs(1,visited,adj,correct_guess,parent,k);


        if(ans==0){
            cout<<"0/1"<<endl;
        }else{
            int gcd = __gcd(ans,N);
            cout<<(ans/gcd)<<"/"<<(N/gcd)<<endl;
        }
    }
    return 0;
}

