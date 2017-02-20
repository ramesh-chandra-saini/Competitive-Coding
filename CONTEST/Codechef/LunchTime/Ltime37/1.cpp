#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll t;  cin >> t;
    while(t--){

        ll n,m; cin >> n  >> m;
        ll arr[n][m];
        string  STR;
        for(ll i=0;i<n;i++){
             cin >>STR;
            for(ll j=0;j<m;j++)
                arr[i][j]=(STR[j]=='0')?0LL:1LL;
        }
        ll ans=0LL;
        for(ll j=0;j<m;j++){
            ll boys=0LL;
            for(ll i=0;i<n;i++)
                boys+=arr[i][j];
            ans+=(boys*(boys-1LL))/2LL;
        }
        cout<<ans<<endl;
    }
    return 0;
}
