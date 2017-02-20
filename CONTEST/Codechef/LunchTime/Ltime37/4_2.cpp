#include<bits/stdc++.h>
using namespace std;
bool flag=false;
void searchForNode(int targetNode,vector<int>&Path,vector<set<int> >&arr,vector<int>&searchVisit){

    int lastNode=Path[Path.size()-1];// cout<<lastNode<<endl;
    if(searchVisit[lastNode]==true) return;
    searchVisit[lastNode]=true;
    for(set<int>::iterator it=arr[lastNode].begin(); !flag && it!=arr[lastNode].end();++it){
           if(!flag) Path.push_back(*it);
            if(*it!=targetNode){
                searchForNode(targetNode,Path,arr,searchVisit);
            } else{ flag=true;return; }
            if(Path[Path.size()-1]!=targetNode) Path.erase(Path.begin()+Path.size()-1);
    }
}
int main(){
    int n; cin >> n;
    vector<set<int> >arr(n+1,set<int>());
    int u,v;
    for(int i=1;i<n;i++){
        cin >> u >> v;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    int q; cin >> q;
    vector<bool> visit(n+1,false);
    while(q--){
        cin >> u >> v;
        int ans=0;
        flag=false;
        if(u==v){
            ans=visit[u];visit[u]=false;
        }else{
            vector<int>Path; Path.push_back(u);
            vector<int>searchVisit(n+1,false);
            searchForNode(v,Path,arr,searchVisit);

            for(int i=0;i<Path.size();i++){
                ans+=visit[Path[i]];
            }
            for(int i=0;i<Path.size();i++){
                visit[Path[i]]=true;
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}
