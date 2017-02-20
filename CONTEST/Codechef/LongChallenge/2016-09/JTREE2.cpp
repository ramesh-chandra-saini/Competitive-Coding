#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef struct Ticket{
    ll city, times, cost;
} ticket;

int main(){
    ll N, M; cin >> N >> M;
    vector<ll> tree(N+1);
    vector<vector<ll> > adjList(N+1,vector<ll>());
    for(ll i=1;i<N;i++){
        ll a,b; cin >> a >> b;
        tree[a]=b;
        adjList[b].push_back(a);
    }
    ll level=0;
    vector<ll>  levelRegister(N+1);
    queue<ll> levelList; levelList.push(1); //push root
    while(!levelList.empty()){
        level++;
        queue<ll> nextLevelList;
        while(!levelList.empty()){
            ll node = levelList.front(); levelList.pop();
            levelRegister[node]=level;
            for(int i=0;i<adjList[node].size();i++){
                nextLevelList.push(adjList[node][i]);
            }
        }
        levelList=nextLevelList;
    }
    map<ll,vector<ll> > levelHolder;
    for(ll i=1;i<=N;i++){
        levelHolder[levelRegister[i]].push_back(i);
    }
    ll numberOfLevel=0;
    for(map<ll,vector<ll> >::iterator it=levelHolder.begin();it!=levelHolder.end();++it){
        cout<<it->first << "  ";
        numberOfLevel = max(numberOfLevel,it->first);
        for(ll i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
    for(ll i=numberOfLevel;i>0;i--){
        vector<ll> listOfNode = levelHolder[i];
        cout<<i<<" --> ";
        for(ll j=0;j<listOfNode.size();j++){
            cout<<listOfNode[j]<<" ";
        }
         cout<<endl;
    }


    vector<ticket> tickets(M);
    for(ll i=0;i<M;i++){
        cin >> tickets[i].city >> tickets[i].times >> tickets[i].cost;
    }
    ll Q; cin >> Q; while(Q--){
        int h; cin >> h;
        int ans=0;
        cout<<ans<<endl;
    } return 0;
}
