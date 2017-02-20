#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n; cin >> n;
    vector<ll> arr(n); for(int i=0;i<n;i++) cin >> arr[i];
    vector<ll> ans(n); ans[n-1]=arr[n-1];
    for(ll i=n-2;i>=0;i--){
        ans[i]=arr[i]+arr[i+1];
    }
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
