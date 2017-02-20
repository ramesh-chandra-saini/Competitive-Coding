#include<bits/stdc++.h>
using namespace std;
#define VAR 25
#define ll long long int
int main(){
    ll n; cin >> n;
    vector<ll> arr(n); for(ll i=0;i<n;i++) cin >> arr[i];
    ll ans=INT_MAX;
        vector<ll> copy(n);
        for(ll i=0;i<n;i++){
            for(ll var = -VAR;var<=VAR;var++){
                copy[i]=arr[i]+var;
                for(ll j=i;j>0;j--)
                    copy[j-1]=copy[j]-(j);
                for(ll j=i;j<n-1;j++)
                    copy[j+1]=copy[j]+(j+1);
                ll currCost=0;
                for(ll j=0;j<n;j++)
                    currCost+=abs(copy[j]-arr[j]);
                ans=min(ans,currCost);
            }
        }
        cout<<ans<<endl;
    return 0;
}
