#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll M; cin >> M;
    map<ll,ll> primeFactor;
    for(ll i=2LL;i*i<=M;i++)
        while(M%i==0)
            ++primeFactor[i],M/=i;
    if(M>1)
        ++primeFactor[M];
    for(map<ll,ll> ::iterator it=primeFactor.begin();it!=primeFactor.end();it++)
        cout<<it->first<<"^"<<it->second<<" * "; cout<<endl;
    ll phi = 1LL:
    for(map<ll,ll> ::iterator it=primeFactor.begin();it!=primeFactor.end();it++){
        ll p = it->first,a=it->second;
    }
    return 0;
}
