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
            if(timer>k){
                ans+=T*D;
            }else{
                if(timer+T<=k){
                    ans+=0;
                }else{
                    ans+=(timer+T-k)*D;
                }
            }
            timer+=T;
        }
        cout<<ans<<endl;
    }

}
