#include<bits/stdc++.h>
using namespace std;

set<int>  adj[1000006];
int    parent[1000006];
bool  visited[1000006];
int  dist[1000006];

vector<pair<int,int> > E;
int N;

int bfs(int root,int &max_dist){


        for(int i=1;i<=N;i++){

            parent[i] = i;
            visited[i] = false;
            dist[i] = 0;
        }


    queue<int> Q;
    Q.push(root);

    parent[root] = root;
    visited[root] = true;
    max_dist = 0;
    dist[root] = 0;
    int endPoint = root;

    while(!Q.empty()){

        int u = Q.front();
       // cout<<u<<" ";
        Q.pop();
        endPoint = u;

        for(set<int>::iterator j=adj[u].begin();j!=adj[u].end();j++){

            int next = *j;

            if(!visited[next]){

                visited[next] = true;
                parent[next] = u;
                dist[next] = dist[u]+1;
                max_dist = max(max_dist,dist[next]);
                Q.push(next);
            }
        }
    }
    //cout<<endl;
    return endPoint;
}
int getDia(int u){
    int max_dist = 0;
    int endPoint  = bfs(u,max_dist);
    max_dist = 0;
    bfs(endPoint,max_dist);
    return max_dist;
}
int main(){

    cin >> N;
    for(int i=1;i<N;i++){
        int u,v;
        cin >> u >> v;
        E.push_back(make_pair(u,v));
        adj[u].insert(v);
        adj[v].insert(u);

    }
    int ans = 0;

    for(int i=0;i<E.size();i++){

        //remove Edge one by one
        int u = E[i].first;
        int v = E[i].second;

        adj[u].erase(v);
        adj[v].erase(u);

        ans = max(ans, getDia(u)+1+getDia(v));

        //add removed Edge
        adj[u].insert(v);
        adj[v].insert(u);


    }
    cout<<ans<<endl;
    return 0;
}
