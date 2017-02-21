#include<bits/stdc++.h>
using namespace std;
#define MAX (1LL<<62LL)
#define ll long long
ll getEnergy(vector<ll>&box,vector<ll>&E){
    ll ans = 0LL;
    for(ll i=0;i<box.size();i++){
        ll s = box[i],k=0LL;
        for(ll j=0;j<box.size();j++)
            k+=(box[j]>box[i]);
        ans+=E[i]*k;
    } return ans;
}
int main(){
    ll t; cin >> t; while(t--){
        ll n, m ; cin >> n >> m ;
        vector<ll> E(n); for(ll i=0;i<n;i++) cin >> E[i];
        vector<ll> box(n,0);
        ll ans = 0LL;
        while(m--){
            ll Energy = MAX;
            ll id=0;
            for(int i=0;i<n;i++){
                box[i]++;
                ll currEnergy = getEnergy(box,E);
                if(Energy>currEnergy){
                    id = i;
                    Energy=currEnergy;
                }
                box[i]--;
            }
            box[id]++;
        }
        for(ll i=0;i<n;i++)
            cout<<box[i]<<" "; cout<<endl;
        cout<<getEnergy(box,E)<<endl;
    } return 0;
}
