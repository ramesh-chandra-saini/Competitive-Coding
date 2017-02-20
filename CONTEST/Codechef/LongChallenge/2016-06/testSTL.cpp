#include<bits/stdc++.h>
using namespace std;
#define ll long long  int
int main(){
    ll n,m; cin >> n >> m;
    ll arr[n+1][m+1][5];
    for(ll i=1;i<=n;i++)for(int j=1;j<=m;j++)cin >> arr[i][j][0];
    map<ll, map<ll,ll> > vmap;
    map<ll,set<ll> > vset;
    map<ll, map<ll,ll> >:: iterator mit;
    map<ll, set <ll> > :: iterator sit;
    for(ll j=1;j<=m;j++){
        for(ll i=1;i<=n;i++){
            (vmap[j])[arr[i][j][0]]++;
            (vset[j]).insert((-1)*arr[i][j][0]);
        }
    }
    return 0;
}
