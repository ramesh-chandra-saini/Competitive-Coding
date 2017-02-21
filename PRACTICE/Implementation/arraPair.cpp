#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
        cin >> arr[i];
    ll ans = 0;
    for(ll i=0;i<n;i++){
        set<ll> mySet;mySet.clear();
        mySet.insert(-arr[i]);
        for(int j=i+1;j<n;j++){
            mySet.insert(-arr[j]);
            ll mx = -*mySet.begin();
            if(arr[i]*arr[j]<=mx)
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
