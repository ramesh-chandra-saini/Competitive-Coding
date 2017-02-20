#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define height first
#define rate second

ll currWoodAmount( vector<pair<ll,ll> > &Tree,ll N,ll L,ll Time){
    ll ans=0;
    for(ll i = 0 ; i < N ; i++ )
    ans+=(L>Tree[i].height+Time*Tree[i].rate)?0:Tree[i].height+Time*Tree[i].rate;
    return ans;
}
void findMinTime(  vector<pair<ll,ll> > &Tree , ll N, ll W , ll L , ll minTime, ll maxTime,ll & final_ans){

    if(minTime>maxTime) return;
    ll Time = (minTime+maxTime)/2LL;
    ll currAmount=currWoodAmount(Tree,N,L,Time);
    if(currAmount>=W){
        final_ans=min(final_ans,Time);
        findMinTime(Tree,N,W,L,minTime,Time-1,final_ans);
    }
    else findMinTime(Tree,N,W,L,Time+1,maxTime,final_ans);
}
int main(){

    ll N,W,L;cin >> N >> W >> L;
    vector<pair<ll,ll> > Tree(N);
    for(ll i=0;i<N;i++)
        cin >> Tree[i].height >> Tree[i].rate;
    ll minTime=0,maxTime=INT_MAX,final_ans=INT_MAX;
    findMinTime(Tree,N,W,L,minTime,maxTime,final_ans);
    cout<<final_ans<<endl;
    return 0;
}
