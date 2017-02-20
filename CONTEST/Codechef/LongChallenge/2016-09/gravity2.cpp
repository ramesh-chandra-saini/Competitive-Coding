#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll  BFS(ll N,ll currNode, ll target,vector<vector<ll> >&adjList){
    ll currAns=0;
    if(currNode==target){
        currAns=0;
    } else{   ll refDis=0;
        vector<ll> visit(N+1,false);
        queue<ll> level; level.push(currNode);level.push(-1);
        visit[currNode]=true;
        while(!level.empty()){
            ll node = level.front();level.pop();
            if(node==target){
                currAns=refDis*refDis; break;
            }else if(node==-1) level.push(-1),refDis++;
            else{
                for(ll i=0;i<adjList[node].size();i++){
                    if(visit[adjList[node][i]]==false){
                        level.push(adjList[node][i]);
                        visit[adjList[node][i]]=true;
                    }
                }
            }
        }
    }
    //cout<<currNode<<" "<<target<<" : "<<currAns<<endl;
    return currAns;
}
ll Dis(ll b,vector<ll>&parent,map<ll,ll>&mapLCA){
    int idx=0;
    while(true){
        idx++;
        if(mapLCA.find(b)!=mapLCA.end()) break;
        else   b=parent[b];
    }
    ll dis = (mapLCA[b]-1)+(idx-1);
    cout<<dis*dis<<endl;
    return dis*dis;
}
map<ll,ll> preprocessing(ll currNode,vector<ll>&parent){
    ll a = currNode;
    stack<ll> currNodePath;
    do{
        currNodePath.push(a);
        a=parent[a];
    }while(a);

    map<ll,ll> mapLCA;
    ll idx=currNodePath.size();
    while(!currNodePath.empty()){
        ll node = currNodePath.top();currNodePath.pop();
        mapLCA[node]=idx--;
    }
    return mapLCA;
}
ll ans=0;
void BFSDir(ll N,ll currNode,ll target,vector<vector<ll> >&adjList,vector<vector<ll> >&adjListDir,
            vector<ll>&parent){
    map<ll,ll> mapLCA = preprocessing(currNode,parent);
    queue<ll> level; level.push(target);
    ans+=Dis(target,parent,mapLCA);
    while(!level.empty()){
        ll node = level.front();level.pop();
           for(ll i=0;i<adjListDir[node].size();i++){
                    level.push(adjListDir[node][i]);
                    ans+=Dis(adjListDir[node][i],parent,mapLCA);
           }
    }
}
int main(){
    ll n; cin >> n;
    vector<vector<ll> > adjList(n+1,vector<ll>());
    vector<vector<ll> > adjListDir(n+1,vector<ll>());
    vector<ll> parent(n+1); parent[1]=0;
    for(ll k=1,value;k<n;k++){
        cin >> value;
        adjList[value].push_back(k+1);
        adjList[k+1].push_back(value);
        adjListDir[value].push_back(k+1);
        parent[k+1]=value;
    }
    ll q; cin >> q; while(q--){
        ll ref,pt; cin >> ref >> pt;
        ans=0;
        BFSDir(n,ref,pt,adjList,adjListDir,parent);
        cout<<ans<<endl;
    } return 0;
}
