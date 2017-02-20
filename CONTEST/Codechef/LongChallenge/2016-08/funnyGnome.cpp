#include<bits/stdc++.h>
using namespace std;
void print(set<int>&vec){
    for(set<int>::iterator it=vec.begin();it!=vec.end();++it) cout<<*it<<" "; cout<<endl;
}
void traverseKUnitInGraph(vector<vector<int> >&graph,int k,set<int>&curr){
    if(k<=0||curr.empty()) return;
    set<int>next;//print(curr);
    for(set<int>::iterator it=curr.begin();it!=curr.end();it++) {
        int currNode=*it; //cout<<currNode<<",";
        for(int j=0;j<graph[currNode].size();j++)
                next.insert(graph[currNode][j]);
    }curr=next;
    traverseKUnitInGraph(graph,k-1,curr);
}
int main(){
    int n,yes;cin >> n;
    vector<vector<int> > graph(n+1,vector<int>());
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){cin>>yes;if(yes==1)graph[i].push_back(j);}
    int m; cin >> m;while(m--){
        int k,x; cin >> k >> x;
        set<int> curr; curr.insert(x);
        traverseKUnitInGraph(graph,k,curr);
        cout<<curr.size()<<endl;
        if(curr.empty()) cout<<"-1"<<endl;
        else print(curr);
    } return 0;
}
