#include<bits/stdc++.h>
using namespace std;
#define ll long  long
int main(){
    ll N; cin >> N;
    ll ans=0;
    for(ll n=2;n<=N;n++)
        for(ll k=2;k*k<=n;k++)
            if(n%k==0)
                ans+=__gcd(k,n/k)==1;
    cout<<ans<<endl;
    return 0;
}
