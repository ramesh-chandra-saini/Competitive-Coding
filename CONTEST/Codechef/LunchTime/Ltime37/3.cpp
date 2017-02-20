#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000000
ll breaker=0LL;
void primeFactors(ll n, map<ll,bool> & myMap,ll &ans){
    while (n%2LL == 0){
        if(myMap[2LL]==true) {ans=2LL;break;}
        else myMap[2LL]=true;
        n = n/2LL;
    }

    for (ll i = 3LL; i*i<=n; i+=2LL){
        if(breaker>MAX) return;
        while (n%i == 0LL){
            if(myMap[i]==true) {ans=i; return;}
            else myMap[i]=true;
            n = n/i;

        }
    }
    if (n > 2){
        if(myMap[n]==true) {ans=n; return;}
        else myMap[n]=true;
    }
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll,bool> myMap;
        ll ans=0LL,N;
        ll arr[n];
        breaker=0LL;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll gcd =__gcd(arr[i],arr[j]);
                if(gcd>1LL) {ans=gcd;break; }
            }
        }
        for(ll i=0;i<n;i++)
            if(ans==0) primeFactors(arr[i],myMap,ans);
        cout<<ans<<endl;
    }

}
