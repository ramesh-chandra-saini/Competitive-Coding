#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){

    ll n;
    cin >> n;

    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    ll value=0;
    ll ans=0;
    for(ll i=0;i<n;i++ ){

        ans+=abs(value-arr[i]);
        value+=(arr[i]-value);
    }
    cout << ans<<endl;
    return 0;
}
