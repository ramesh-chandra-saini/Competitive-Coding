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
    ll t;cin >> t; while(t--){
        ll n; cin >> n;
        ll arr[n+1]; for(ll i=1;i<=n;i++) cin >> arr[i];
        ll start,end,ans=0; cin >> start >> end;
        if(n==1) ans=2*arr[1];
        else{
        ll FC=0LL;ll curr=start;
        while(curr!=end){
            FC=FC+arr[curr];
            curr = (curr%n)+1LL;
        }
        ll BC=0LL; curr=start;
        while(curr!=end){
            curr=(curr==1LL)?n:curr-1LL;
            BC=BC+arr[curr];
        }
        ans=min(FC,BC);
        ll fc=0LL; curr=start;
        while(curr!=end){
            fc=fc+arr[curr];
            curr=(curr)%n+1LL;
            ans=min(ans,2LL*fc+BC);
        }
        ll bc=0LL;
        while(curr!=end){
            curr=(curr==1LL)?n:curr-1LL;
            bc=bc+arr[curr];
            ans=min(ans,2LL*bc+FC);
        }}
        cout<<ans<<endl;
    } return 0;
}
