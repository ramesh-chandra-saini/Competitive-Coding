#include<bits/stdc++.h>
using namespace std;
vector<int> nodeList;
void DFS(int currNode,map<int,vector<int> >&adjList,vector<bool>&processedNode,vector<bool>&visit){
    if(visit[currNode]==true){
        for(int i=0;i<nodeList.size();i++){
            processedNode[nodeList[i]]=true;
        }
        return ;
    }else{
        visit[currNode]=true;

        for(int i=0;i<adjList[currNode].size();i++){
            int childe = adjList[currNode][i];
            if(visit[childe]==false){
             nodeList.push_back(currNode);
                DFS(childe,adjList,processedNode,visit);
                 nodeList.pop_back();
            }
        }

    }
}
int main(){
    int N,M; cin >> N >> M;
    map<int,vector<int> > adjList;
    map<pair<int,int>,int>weight;
    for(int x,y,w;M--;){
        cin >> x >> y >> w;  weight[make_pair(x,y)]=w; adjList[y].push_back(x);
    }
    vector<int> chocolate(N+1,0);
    vector<bool> processedNode(N+1,false);

    for(int i=1;i<=N;i++){
        nodeList.clear();
        vector<bool> visit(N+1,false);

            DFS(i,adjList,processedNode,visit);
    }

    for(int i=1;i<=N;i++){
        set<int> curr;   //check incoming edges
        for(map<int,vector<int> >::iterator it=adjList.begin();it!=adjList.end();++it){
            vector<int> child = it->second; //cout<<it->first<<" -> ";
            for(int j=0;j<child.size();j++){
                curr.insert(child[j]);// cout<<child[j]<<" ";
            } //cout<<endl;
        }     //select node which doesn't have any incoming edge
        bool existSuchNode=false;
        for(int j=1;j<=N;j++){
            if(curr.find(j)==curr.end() && processedNode[j]==false){
                int node = j; existSuchNode=true; //this is not gready friend and has only outgoing edges right now
                chocolate[node]=max(1,chocolate[node]);
                vector<int> child = adjList[node];
                for(int i=0;i<child.size();i++){
                    int add  = weight[make_pair(child[i],node)];
                    int currDiff = chocolate[child[i]]-chocolate[node];
                    int diff = add-currDiff;
                    chocolate[child[i]]+=(diff>0)?diff:0;
                }
                processedNode[j]=true; adjList.erase(node);
            }
        }
        if(existSuchNode==false)//no node which is having only incoming edge
            break;
    } //for(int i=1;i<=N;i++) cout<<chocolate[i]<<" "; cout<<endl;
    int finalAns=0;  for(int i=1;i<=N;i++) finalAns+=chocolate[i];
    cout<<finalAns<<endl;
    return 0;
 }
