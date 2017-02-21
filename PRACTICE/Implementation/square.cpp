#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin >> arr[i];

        if(n<=2){
            ll num = 1LL;
            for(ll i=0;i<n;i++)
                num*=arr[i];

        }else{

        }
    }
    return 0;
}
