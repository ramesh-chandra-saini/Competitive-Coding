/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
int ans=0;
void DFS(vector<int>&tree, vector<bool>&visit,int root,vector<int>&currPath,set<int>&currSet){
    if(visit[root]==true){
        int currCycleLength=0; bool found=(currSet.find(root)!=currSet.end());
        while(!currPath.empty()){
            if(currPath.back()==root) {
                    currSet.erase(currPath.back()),currCycleLength++,currPath.pop_back();break;
            } else currSet.erase(currPath.back()), currCycleLength++,currPath.pop_back();
        }if (found)ans+=currCycleLength;return ;
    }
    visit[root]=true,currPath.push_back(root),currSet.insert(root);
    DFS(tree,visit,tree[root],currPath,currSet);
}
int main(){
    int t; scanf("%d",&t); while(t--){
        int n; scanf("%d",&n); vector<int>tree(n);
        vector<int> skip(n); for(int i=0;i<n;i++) scanf("%d",&skip[i]);
        for(int i=0;i<n;i++) tree[i]=((i+skip[i]+1)%n);
        ans=0; vector<bool> visit(n,false);
        fflush(stdout);
        for(int i=0;i<n;i++){
            vector<int> currPath;  set<int> currSet;
            if(!visit[i])  DFS(tree,visit,i,currPath,currSet);
        } printf("%d\n",ans);

    } return 0;
}
