/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin >> t; while(t--){
        ll n; cin >> n; vector<ll>w(n+1LL,0LL); for(ll i=1LL;i<=n;i++) cin>>w[i];
        ll source,dest,ans=0; cin >> source >>  dest;
        if(n)
        ll forwardCost=0LL,curr=source;
        while(curr!=dest)forwardCost+=w[curr],curr=(curr%n)+1LL;
        ll backwardCost=0LL;curr=source;
        while(curr!=dest)  curr=(curr==1LL)?n:curr-1LL,backwardCost+=w[curr];
        ans=min(forwardCost,backwardCost);
        ll fc=0LL;curr=source;
        while(curr!=dest)fc+=w[curr],curr=(curr%n)+1LL,ans=min(ans,2LL*fc+backwardCost);
        ll bc=0LL;curr=source;
        while(curr!=dest)curr=(curr==1LL)?n:curr-1LL,bc+=w[curr],ans=min(ans,2LL*bc+forwardCost);
        cout<<ans<<endl;
    }return 0LL;
}
