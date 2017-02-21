#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin >>t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vector<ll> A(n+1,0),B(m+1,0);
        for(ll i=1;i<=n;i++)
            cin >> A[i],A[i]+=A[i-1];
        for(ll i=1;i<=m;i++)
            cin >> B[i],B[i]+=B[i-1];
        ll ans = 0;
        for(ll i=0;i<=n;i++){
            ll num = k-A[i];
            if(num<0)
                break;
            ll p = upper_bound(B.begin(),B.end(),num)-B.begin()-1;
            ans = max(ans,i+p);
        }
        cout<<ans<<endl;
    }
    return 0;
}
