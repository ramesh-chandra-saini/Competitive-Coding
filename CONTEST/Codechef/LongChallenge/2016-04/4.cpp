#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll __expo(ll N, ll pw){
    ll ans=1LL;
    while(pw){
        if(pw%2) ans=(ans*N)%MOD;
        N=(N*N)%MOD;pw/=2LL;
    }
    return ans;
}
int main(){
    ll t,N,K; cin >> t;
    while(t--){
        cin >> N >> K;
        cout<<((K*__expo(K-1,N-1))%MOD)<<endl;
    }
    return 0;
}
