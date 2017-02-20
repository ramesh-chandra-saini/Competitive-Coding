#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll ans = 0;
        ll timer = 0;
        while(n--){
            ll T,D; cin >> T >> D;
            ans+=(timer+T-k>0)?(timer+T-k)*D:0;
            timer+=T;
        }
        cout<<ans<<endl;
    }

}
