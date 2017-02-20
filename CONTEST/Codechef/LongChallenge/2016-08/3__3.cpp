#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long int
ll getNext(ll curr,ll n){    return curr==n?1LL:curr+1LL;}
ll getPrev(ll curr,ll n){    return curr==1LL?n:curr-1LL;}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans=INT_MAX;
        if(n==2){
            ll a,b; cin >> a >> b;
            ans=min(ans,min(min(a,b),min(2*a+b,2*b+a)));
        }else{


        map<pair<ll,ll>,ll>graph;graph.clear();
        for(ll i=1LL,w;i<=n;i++) {
            cin >>w;
            graph[mp(i,(i%n)+1LL)]=w;
            graph[mp((i%n)+1LL,i)]=w;
        }
        ll src,dest; cin >> src >> dest;

            ll forwardCost=0LL;
            //use forward path
            for(ll curr=src,next;curr!=dest;curr=next){
                next=getNext(curr,n);
                forwardCost=forwardCost+graph[mp(curr,next)];
            }
             ans=min(ans,forwardCost);
            //use backward path
            ll backwardCost=0LL;
            for(ll curr=src,next;curr!=dest;curr=next){
                next=getPrev(curr,n);
                backwardCost=backwardCost+graph[mp(curr,next)];
            }
            ans=min(ans,backwardCost);

            //use 2*fc and backward
            for(ll curr=src,fc=0LL,next;curr!=dest;curr=next){
                next=getNext(curr,n);
                fc=fc+graph[mp(curr,next)];
                ans=min(ans,2LL*fc+backwardCost);
            }
            //use 2*bc and forward
           for(ll curr=src,bc=0LL,next;curr!=dest;curr=next){
                next=getPrev(curr,n);
                bc=bc+graph[mp(curr,next)];
                ans=min(ans,2LL*bc+forwardCost);
            }
            //use forward and 2*fc
            for(ll curr=dest,fc=0LL,next;curr!=src;curr=next){
                next=getNext(curr,n);
                fc=fc+graph[mp(curr,next)];
                ans=min(ans,2LL*fc+forwardCost);
            }
            //use backword and 2*bc
            for(ll curr=dest,bc=0LL,next;curr!=src;curr=next){
                next=getPrev(curr,n);
                bc=bc+graph[mp(curr,next)];
                ans=min(ans,2LL*bc+backwardCost);
            }
            //one full round and forward cost
            ans=min(ans,backwardCost+forwardCost+backwardCost);
            //one full round and  backword cost
            ans=min(ans,forwardCost+backwardCost+forwardCost);
            }
            cout<<ans<<endl;
    } return 0LL;
}
