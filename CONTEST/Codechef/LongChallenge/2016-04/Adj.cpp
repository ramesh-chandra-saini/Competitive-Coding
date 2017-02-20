#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; while(t--){
    int A,B; cin >> A >> B; bool graph[A][A]; memset(graph,false,sizeof(graph));
    int x,y;
    while(B--){
        cin >> x >> y; x--;y--; graph[x][y]=graph[y][x]=true;
    }
    bool visit[A];for(int i=0;i<A;i++) visit[i]=false; vector<int> child; child.clear();
    child.push_back(0);//start from root node 0
    int ans[A]; for(int i=1;i<A;i++) ans[i]=INT_MAX;
    vector<int> childChild; childChild.clear(); int Luckiness=0;
    vector<vector<int> > GRAPH(A); for(int i=0;i<A;i++) GRAPH.clear();
    for(int i=0;i<A;i++){
        for(int j=0;j<A;j++){
            if(graph[i][j]) GRAPH[i].push_back(j);
        }
    }
    while(child.size()>0){  childChild.clear();
        for(int i=0;i<child.size();i++){
            int node = child[i];
            ans[node]=min(ans[node],Luckiness);
            visit[node]=true;
            for(int j=0;j<GRAPH[node].size();j++){
               int nodes=GRAPH[node][j];
                if(!visit[nodes] ){
                    childChild.push_back(nodes);
                }
            }
        }
        child=childChild;++Luckiness;
    }
    cout<<ans[A-1]<<endl;
    /*for(int i=1;i<A;i++){
        if(ans[i]==INT_MAX) cout<<"INF"<<endl;
        else cout<<ans[i]<<endl;
    }*/
    }
    return 0;
}
