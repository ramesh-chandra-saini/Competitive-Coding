#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;while(t--){
        ll a,b,c,d; cin >> a >> b >>c >>d;

        ll ans=0;
        for(ll x=a;x<=b;x++){
            ll mx = d;
            ll mn = max(x+1,c);
            ll diff = mx-mn+1;
            ans+=(diff>0)?diff:0;
        }
        cout<<ans<<endl;
    } return 0;
}
