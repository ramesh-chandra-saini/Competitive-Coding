/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
==============================================================
            #BruteForce
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n,m,b,c; cin>>n>>m>>b>>c;
    vector<vector<ll> > powerTransfer(n+1,vector<ll>(n+1,0));
    for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) cin >> powerTransfer[i][j];
    set<pair<ll,ll> > loadSet;
    for(ll i=1;i<=n;i++) loadSet.insert(make_pair(0,i));
    for(ll batch=1;batch<=m;batch++){
        ll budget=c;
        set<pair<ll,ll> > currSet;
        ll node,power; vector<ll> ans(n+1);
        for(ll job=1;job<=b;job++){
            cin>>node>>power;currSet.insert(make_pair(-power,node)); ans[job]=node;
        } ll jobNumber=1;
        for(set<pair<ll,ll> > :: iterator it=currSet.begin();it!=currSet.end();++it,jobNumber++){
            pair<ll,ll> leastLoadNode=*loadSet.begin();
            pair<ll,l> highestLoadCurrNode=*it;
            ll from = highestLoadCurrNode.second;
            ll t= leastLoadNode.second;
            if(powerTransfer[from][to]<=budget){
                budget-=powerTransfer[from][to];

            }
        }

    }

}
