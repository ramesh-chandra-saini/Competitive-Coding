/*
    Author : Ramesh Chandra
    National Institute Of Technology Karnataka Surathkal
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll NODE(ll N,vector<bool>&RealLeaf,vector<vector<ll> >&graph,ll __N){

    if( N==RealLeaf[N]) return 0LL;
    ll ans=0;
    for(int i=1;i<=__N;i++){
        ans=max(ans,graph[N][i]+NODE(i,RealLeaf,graph,__N));
    }
    return ans;
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n; // number of nodes
        ll hash[n+1],tree[n+1][2];memset(tree,0,sizeof(tree)); memset(hash,0,sizeof(hash));//storing frequency of all nodes, which will help to know which is leaf node
        tree[1][0] = 1; tree[1][1] = 0;
        for(ll i=0,x,y,w,temp;i<n-1;i++){
            cin >> x >> y >> w; if(x>y) swap(x,y); //child always has higher id to parent
            tree[y][0] = x;tree[y][1] = w;//storing tree into array
            hash[x]++,hash[y]++; //storing frequency into hash
        }
        vector<bool> RealLeaf(n+5);
        vector<ll> Leaf,Releaf;//store current leaf nodes
        for(ll i = 2;i<=n;i++) //skip root node
            if(hash[i] == 1 ) Leaf.push_back(i),RealLeaf[i]=true;//freq == 1 means Leaf node..as simple as u think
        vector<vector<ll> > Jungle(n+5);
        vector<vector<ll> > graph(n+5,vector<ll>(n+5,0));// memset(graph,0,sizeof(graph));
        for(int i =0;i<n+5;cout<<endl,i++) for(int j=0;j<n+5;cout<<graph[i][j]<<" ",j++)
        for(ll i=1;i<=n;i++) Jungle[i].push_back(i);
        vector<ll> ans(n+5,0);
        while(1){
                for(int i=0;i<Leaf.size();i++) cout<<Leaf[i]<<" "; cout<<endl;
                Releaf.clear();
                for(int i=0,x,y;i<Leaf.size();i++){
                    y=Leaf[i]; x=tree[y][0];
                    ll currmin=INT_MAX;
                    for(int j=0;j<Jungle[y].size();j++){ cout<<Jungle[y][j]<<" ";
                        currmin = min(currmin,NODE(Jungle[y][j],RealLeaf,graph,n));
                    }  cout<<endl;
                     for(int j=0;j<Jungle[y].size();j++)
                               Jungle[x].push_back(Jungle[y][j]);
                    ans[y]=currmin;
                    //for next scenerio
                    graph[x][y] = graph[y][x] = tree[y][1];
                    hash[x]--; hash[y]--;
                    if(x!=1 && hash[x]==1) Releaf.push_back(x);
                }
                if(Releaf.size()) Leaf=Releaf;
                else break;
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    }
    return 0;
}
