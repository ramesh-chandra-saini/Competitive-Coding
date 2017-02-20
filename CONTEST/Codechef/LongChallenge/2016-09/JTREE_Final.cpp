/*
    Author : Ramesh Chandra
    National Institute of Technology Karnataka Surathkal
    DFS, DP, Segment Tree
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX (1LL<<62)
#define read(x) scanf("%lld",&x)
#define write(x) printf("%lld\n",x)
ll u(ll position){
    return max(1LL,position);
}
void update(ll position,ll value,ll ss, ll se, ll index,vector<ll>&segTree){
    if(ss>se){
        return;//base case
    } else if(ss==position && se==position){
        segTree[index]=value;
        return ;
    }else{
        ll mid = (ss+se)/2LL;
        if(ss<=position && position<=mid){
            update(position,value,ss,mid,2LL*index+1LL,segTree);
        }else{
            update(position,value,mid+1LL,se,2LL*index+2LL,segTree);
        }
        segTree[index]=min(segTree[2LL*index+1LL],segTree[2LL*index+2LL]);
    }
}
ll getMin(ll qs,ll qe,ll ss,ll se,ll index,vector<ll>&segTree){
    if(qe<ss || se<qs || qs>qe || ss>se) {
        return MAX;
    }else if(qs<=ss && se<=qe){
        return segTree[index];
    }else{
        ll mid = (ss+se)/2LL;
        return min(
                getMin(qs,qe,ss,mid,2LL*index+1LL,segTree),
                getMin(qs,qe,mid+1LL,se,2LL*index+2LL,segTree)
        );
    }
}
void DFS(ll currNode, ll level,ll N,vector<ll>&visit,vector<ll>&dp,vector<set<ll> >&adjList,map<ll,set<pair<ll,ll> > >&ticket,
                vector<ll>&segTree){
    if(visit[currNode]) return;
    visit[currNode]=true;//cout<<currNode<<"["<<level<<"]"<<endl;
    for(set<pair<ll,ll> >::iterator it=ticket[currNode].begin();it!=ticket[currNode].end();++it){
        ll distance=it->first,cost=it->second;
        dp[currNode]=min(dp[currNode],cost+getMin(u(level-distance),u(level-1),1LL,N,0LL,segTree));
    }
    update(level,dp[currNode],1LL,N,0LL,segTree);
    //process this node
    for(set<ll>::iterator it=adjList[currNode].begin();it!=adjList[currNode].end();++it){
        if(!visit[*it]){
            DFS(*it,level+1,N,visit,dp,adjList,ticket,segTree);
        }
    }
}
int main(){
    ll N,M; read(N),read(M);
    ll segSize = 10*N*(1LL+ceil(log2(N)));
    vector<ll> segTree(segSize,MAX);
    vector<set<ll> > adjList(N+1LL,set<ll>());
    for(ll i=1LL,u,v;i<N;i++){
        read(u),read(v);
        adjList[v].insert(u);
    }
    map<ll,set<pair<ll,ll> > >ticket;
    for(ll v,k,w;M>0LL;M--){
        read(v),read(k),read(w);
        ticket[v].insert(make_pair(k,w));
    }
    vector<ll> dp(N+1LL,MAX);
    ll currNode =1LL,level=1LL;
    dp[1LL]=0LL;
    update(level,dp[1LL],1LL,N,0LL,segTree);
    vector<ll> visit(N+1LL,false);
    DFS(currNode,level,N,visit,dp,adjList,ticket,segTree);
    //for(ll i=1;i<=N;i++) cout<<dp[i]<<" "; cout<<endl;
    ll Q; read(Q); while(Q--){
        ll node; read(node);
        write(dp[node]);
    } return 0;
}
