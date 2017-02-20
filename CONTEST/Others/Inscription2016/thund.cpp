#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("in.txt","r",stdin);
    ll n,q; cin >> n >> q;
    vector<ll> arr(n+1); for(ll i=0;i<n;i++) cin >> arr[i+1];
    ll a,b,c,d; cin >> a >> b >> c >> d ;
    ll ans = 0;
    for(ll i=1;i<=q;i++){
        ll L = 1+(a*ans+i*b)%n;
        ll R = L+(c*ans+i*d)%(n-L+1);
        if(L>R) swap(L,R);
        cout<<L<<" "<<R<<endl;
    }
}
