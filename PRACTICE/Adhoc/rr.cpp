#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INT_MAX 100
ll rec(ll N,ll ct,vector<ll>&cost,vector<vector<ll> >&dp,vector<ll>&visit){

    if(ct>=3)
        return INT_MAX;
    if(N==0){
        for(ll i=1;i<visit.size();i++) cout<<visit[i]<<" ";cout<<endl;
        for(int i=visit.size()-1;i>=1;i--){
            if(visit[i]==0)//left
                ct++;
            else
                break;
        }
        if(ct>=3)
            return INT_MAX;
        else
            return 0LL;
    }
 //   if(dp[N][ct]!=-1) return dp[N][ct];
    cout<<N<<" "<<ct<<endl;
    visit[N]=1;
    ll choose = cost[N]+rec(N-1,0LL,cost,dp,visit);
    visit[N]=0;
    ll notChoose = rec(N-1,ct+1,cost,dp,visit);
    cout<<choose<<" "<<notChoose<<endl;
    if(choose<=notChoose){
        visit[N]=1;
        return choose;
    }else{
        visit[N]=0;
        return notChoose;
    }
}
int main(){
    ll N; cin >> N;
    vector<ll> cost(N+1); for(ll i=1;i<=N;i++) cin >> cost[i];
    vector<ll> visit(N+1,-1);
    vector<vector<ll> > dp(N+1,vector<ll>(5,-1));
    ///ll rec(ll N,ll ct,ll cost[],vector<vector<ll> >&dp,vector<ll>&visit)

    cout<<rec(N,0LL,cost,dp,visit)<<endl;
    for(ll i=1;i<=N;i++) cout<<visit[i]<<" ";cout<<endl;
    return 0;
}
