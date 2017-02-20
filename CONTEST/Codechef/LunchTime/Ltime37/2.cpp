#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll t;  cin >> t;
    while(t--){
        ll n,m; cin >> n  >> m;
        ll ans = (n-1)*m+(m-1)*n;
        cout<<ans<<endl;
        }
        return 0;

}
