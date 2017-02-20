#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX (1LL<<62)


void getParentAtKDistance(ll currNode,ll K,vector<ll>&parentList,vector<ll>&dp,ll &parentCost){
    if(K==0 || currNode==1) {
        parentCost=min(parentCost,dp[currNode]);
    }else{
        parentCost=min(parentCost,dp[currNode]);
        getParentAtKDistance(parentList[currNode],K-1,parentList,dp,parentCost);
    }
}
int main(){
    ll n,m; scanf("%lld%lld",&n,&m);
    vector<ll> dp(n+1,MAX);
    vector<set<ll> > adjList(n+1,set<ll>());
    vector<ll> parentList(n+1); for(ll i=0;i<=n;i++) parentList[i]=i;
    for(ll i=1,x,y;i<n;i++){
        scanf("%lld%lld",&x,&y);
        adjList[y].insert(x);
        parentList[x]=y;
    }
    map<ll,set<pair<ll,ll> > > ticket;
    for(ll v,k,w;m>0;m--){
        scanf("%lld%lld%lld",&v,&k,&w);
        ticket[v].insert(make_pair(k,w));
    }
    dp[1]=0LL;
    set<ll> level=adjList[1];
    while(!level.empty()){
        set<ll> nextLevel;nextLevel.clear();
        for(set<ll>::iterator sit=level.begin();sit!=level.end();++sit){
            ll node=*sit;
            set<pair<ll,ll> > tickets;tickets.clear();
            for(set<pair<ll,ll> >::iterator it=ticket[node].begin();it!=ticket[node].end();++it){
               tickets.insert(it->second,it->first);


                ll parentCost=MAX;
                getParentAtKDistance(node,it->first,parentList,dp,parentCost);
                parentCost=dp[parentList[node]];
                dp[node]=min(dp[node],(it->second)+parentCost);
            }

            for(set<ll>::iterator it=adjList[node].begin();it!=adjList[node].end();++it){
                nextLevel.insert(*it);
            }
        }
        level=nextLevel;
    }
    ll q; scanf("%lld",&q); while(q--){
        ll node; scanf("%lld",&node);
        printf("%lld\n",dp[node]);
    } return 0;
}
