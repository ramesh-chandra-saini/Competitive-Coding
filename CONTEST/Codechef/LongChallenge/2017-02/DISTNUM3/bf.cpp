#include<bits/stdc++.h>
using namespace std;
#define ll int

#define pc putchar_unlocked
#define gc getchar_unlocked
inline void read(ll &x)
{
	register ll c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
inline void write(long long int a)
{
    char snum[35];
    int i = 0;
    do
    {
        snum[i++] = a%10 +48;
        a = a/10;

    }while(a!= 0);
    --i;
    while(i>=0)
        pc(snum[i--]);
    pc('\n');
}
void dfs(ll curr,ll target,vector<bool>&visited,vector<vector<ll> > &adj,vector<ll>&pred){
    visited[curr]=true;
    if(curr==target){
        return ;
    }
    for(ll j=0;j<adj[curr].size();j++){
        ll next = adj[curr][j];
        if(!visited[next])
            pred[next]=curr,//storing predecessor of each node, to find path at later stage
            dfs(next,target,visited,adj,pred);
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    ll N,Q; read(N),read(Q);
    ll w[N+1];
    for(ll i=1;i<=N;i++)
        read(w[i]);
    vector<vector<ll> > adj(N+1,vector<ll>());
    for(ll i=1,u,v;i<=N-1;i++)
        read(u),read(v),
        adj[v].push_back(u),
        adj[u].push_back(v);
    ll type,u,v,y;
    while(Q--){
        read(type);
        if(type==1){
            read(u),read(v);
            vector<ll> pred(N+1);
            for(ll i=0;i<=N;i++)
                pred[i]=i;
            vector<bool>visited(N+1,false);
            dfs(u,v,visited,adj,pred);
            set<ll> dist;dist.clear();
            dist.insert(w[v]);
            vector<ll> path; path.push_back(v);
            while(v!=u)
                path.push_back(pred[v]),dist.insert(w[pred[v]]),v=pred[v];
           /*cout<<"PATH : ";
           for(ll i=0;i<path.size();i++)
                  cout<<path[i]<<" "; cout<<endl;
            cout<<"ANS : ";*/
            cout<<dist.size()<<endl;
        }else if(type==2){
            read(v),read(y);
            w[v]=y;
        }
    }
    return 0;
}
