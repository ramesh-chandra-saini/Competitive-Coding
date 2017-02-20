#include<bits/stdc++.h>
using namespace std;
vector<int> getPath(int node,int arr[]){
    vector<int> Path; Path.clear();
    int prevNode;
    do{
        Path.push_back(node);
        prevNode=node;
        node=arr[node];
    }while(prevNode>1);
    //for(int i=0;i<Path.size();i++) cout<<Path[i]<<" --> "; cout<<"ROOT"<<endl;
    return Path;
}
int main(){

    int n; cin >> n;
    int arr[n+1];
    for(int i=0;i<=n;i++) arr[i]=i;
    int u,v;
    for(int i=1;i<n;i++){
        cin >> u >> v;
        if(u>v) swap(u,v);
        arr[v]=u;
    }
    int q; cin >> q;
    vector<bool> visit(n+1,false);
    while(q--){
        cin >> u >> v;
        int ans=0;

            vector<int> uPath = getPath(u,arr);
            vector<int> vPath = getPath(v,arr);
            int uPathSize=uPath.size(), vPathSize=vPath.size(),skip=0;
            while(uPathSize>=1 && vPathSize>=1 && uPath[uPathSize-1]==vPath[vPathSize-1]) uPathSize--,vPathSize--,skip++;
            set<int> nodeSet;
            for(int i=0;i<uPath.size()-skip+1;i++) nodeSet.insert(uPath[i]);
            for(int i=0;i<vPath.size()-skip+1;i++) nodeSet.insert(vPath[i]);
            for(set<int>::iterator it=nodeSet.begin();it!=nodeSet.end();++it)
                ans+=visit[*it];
            for(set<int>::iterator it=nodeSet.begin();it!=nodeSet.end();++it)
                visit[*it]=true;
        cout<<ans<<endl;
    }

    return 0;
}
