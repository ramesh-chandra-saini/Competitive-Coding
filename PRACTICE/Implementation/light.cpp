#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> toggle(ll I,vector<bool> arr,ll K){
    vector<bool> send(arr);
    for(ll i=I,k=K;i>=0 && k>=0;i--,k--)
        send[i] = true ^ arr[i];
    for(ll i=I,k=K;i<arr.size() && k>=0;i++,k--)
        send[i] = true ^ arr[i];
    return send;
}
ll solve(ll I,vector<ll>&cost,ll n,vector<bool> curr,ll k){
    if(I>=n || I<=0){
        for(int i=0;i<curr.size();i++)
            if(curr[i])
                return (1LL<<62);
        return 0;
    }
    vector<bool> togg = toggle(I,curr,k);
    return min(
            min(
                (I+1LL>=n){

                }else
                (1LL+solve(I+1LL,cost,n,togg,k)),
                     solve(I+1LL,cost,n,curr,k)
                ),
            min(
                (1LL+solve(I-1LL,cost,n,togg,k)),
                     solve(I-1LL,cost,n,curr,k)
                )
        );
}
int main(){
    ll n,k; cin >> n>>k;
    vector<ll> arr(n); for(int i=0;i<n;i++) cin >> arr[i];
    vector<bool> curr(n,true);
    cout<<solve(0,arr,n,curr,k)<<endl;
    return 0;
}
