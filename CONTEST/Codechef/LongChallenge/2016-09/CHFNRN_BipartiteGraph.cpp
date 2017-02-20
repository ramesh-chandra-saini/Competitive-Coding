#include<bits/stdc++.h>
using namespace std;
bool globalAns=true;
bool isBipartiteGraph(int n,int currNode,int currColor,vector<int>&color,
    vector<vector<bool> >&graph){
    for(int i=1;i<=n;i++){
        if(graph[currNode][i]){
            if(color[i]==0){//uncolored
             int Color=(currColor==1)?2:1;
                color[i]=Color;
                isBipartiteGraph(n,i,Color,color,graph);

            }else{
                if(color[i]==currColor){ //same colored two node
                    return globalAns=false;
                }else{ //different colored two node
                }
            }
        }
    }
    return true;
}
int main(){
    int t; cin >> t;while(t--){
        int n,m; cin >> n >> m;
        vector<vector<bool> > graph(n+1,vector<bool>(n+1,true));
        while(m--){
            int x,y; cin >> x >> y;
            graph[x][y]=graph[y][x]=false;
        }
        //remove self loop
        for(int i=0;i<=n;i++){
            graph[i][i]=false;
        }
        vector<int> color(n+1,0);
        globalAns=true;
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                int currColor=1,currNode=i;color[i]=1;
                isBipartiteGraph(n,currNode,currColor,color,graph);
            }
        }
        (globalAns)?
                cout<<"YES"<<endl:cout<<"NO"<<endl;
    } return 0;
}
