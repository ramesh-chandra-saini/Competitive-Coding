#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll fastExpo(ll a,ll b,ll c){ll result =1%c;while(b>0){if(b&1)result = (result * a)%c;a = (a*a)%c;b>>=1;}return result;}

int main(){
    ll t;cin >> t; while(t--){
        ll n; cin >> n;
        vector<ll> A(100005,0);
        for(ll i=1,a;i<=n;i++){
            cin>>a;
            A[a]++;
        }
        vector<ll> mc(100005,0);
        for(ll i=1;i<=100000;i++){
            ll j=i;
            while(j<=100000){
                mc[i]=(mc[i]+A[j]);
                j+=i;
            }
        }
        vector<ll> S(100005,0);
        for(ll i=100000; i>=2; i--) {
            ll remove = 0;
            ll j =  2*i;
            while( j <= 100000 ) {
                remove = (remove+S[j]) %(mod-1);
                j += i;
            }
            S[i]= (fastExpo(2LL, A[i],mod-1) - remove+mod-2)%(mod-1); // number of non empty subsets
            // removing subsets with gcd 2 * i, 3 * i...
        }
        ll ans = 1LL;
        for(ll i =2;i<=100000;i++)
            ans = (ans*fastExpo(i,S[i],mod))%mod;
        cout<<ans<<endl;
    } return 0;
}

