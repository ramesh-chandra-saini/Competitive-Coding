#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin >> t;
    while(t--){
        ll K; cin >> K;
        K-=1;
        vector<ll> base5Rep; base5Rep.clear();
        do{
            base5Rep.push_back(K%5), K/=5;
        } while(K);
        for(ll i=0;i<base5Rep.size();i++) base5Rep[i]*=2;
        for(ll i=base5Rep.size()-1;i>=0;i--) cout<<base5Rep[i]; cout<<endl;
    }
    return 0;
}
