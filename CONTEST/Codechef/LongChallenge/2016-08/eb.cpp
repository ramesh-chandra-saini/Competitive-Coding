#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,s; cin >> n >> m >> k >> s;
    int w[n+1]; for(int i=1;i<=n;i++) cin >> w[i];
    vector<vector<int> > graph(n+1,vector<int>());
    while(m--){
        int u,v; cin >> u >> v;
        graph[u].push_back(v),graph[v].push_back(u);
    }
    vector<int> ans; ans.clear();
    vector<int>label; label.push_back(s);
    vector<int> visit(n+1,0); visit[s]=-1;
    do{
        set<pair<int,int> >currLabel; currLabel.clear();
        for(int i=0;i<label.size();i++){
            int currNode=label[i];
            for(int j=0;j<graph[currNode].size();j++){
                int nextNode=graph[currNode][j];
                if(visit[nextNode]==0){
                    currLabel.insert(make_pair(-w[nextNode],nextNode));
                }
            }
        }
        if(currLabel.size()==0) break;
        else{
            pair<int,int> maxNode = *currLabel.begin();
            visit[maxNode.second]=1;
            ans.push_back(maxNode.second);
            label.clear();
            for(set<pair<int,int> >::iterator it=currLabel.begin();it!=currLabel.end();++it){
                if(maxNode!=*it){
                    visit[it->second]=-1;
                    label.push_back(it->second);
                }
            }
        }
        k--;
    } while(label.size()>0&&k>0);
    for(int i=0;i<ans.size();i++) {cout<<ans[i]<<" ";}
    for(int i=ans.size();i<k;i++) {cout<<"1"<<" "; }
    cout<<endl;
    return 0;
}
