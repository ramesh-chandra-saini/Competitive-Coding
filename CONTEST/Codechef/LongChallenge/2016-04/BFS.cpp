#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool graph[A][A];
void dfs(){
    if(node>=A-1) {
        ans=min(ans,Bridges);
         return;
    }else{
        for(int i=0;i<A;i++){

        }
    }
}
int main(){
 memset(graph,false,sizeof(graph));
    int t; cin >> t; while(t--){
    int m[B][2];
    int A,B; cin >> A >> B;
    int x,y;
    for(int i=0;i<B;i++){
        cin >> x >> y; x--;y--; M[i][0]=x;M[i][1]=y; graph[x][y]=graph[y][x]=true;
    }
    ans=INT_MAX; bool visit[A]; for(int i=0;i<n;i++) visit[i]=false; int Bridges=0;int node=0;//start node
    dfs(node,Bridges,A);
    cout<<ans[A]<<endl;
    for(int i=0;i<B;i++) //reset graph to ..initial graph..flush all entry
        graph[M[i][0]][M[i][1]]=graph[M[i][1]][M[i][0]]=false;

    }
    return 0;
}
