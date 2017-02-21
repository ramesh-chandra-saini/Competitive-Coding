#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 123456
//adjacency list
//adj[i] contains all neighbors of i
vector<ll> adj[N];
vector<ll> C(N);

//functions as defined above
ll dp1[N],dp2[N];

//pV is parent of node V
void dfs(ll V, ll pV){

    //for storing sums of dp1 and max(dp1, dp2) for all children of V
    ll sum1=0, sum2=0;

    //traverse over all children
    for(ll i=0;i<adj[V].size();i++){
        ll v = adj[V][i];
        if(v == pV) continue;
        dfs(v, V);
        sum1 += dp2[v];
        sum2 += max(dp1[v], dp2[v]);
    }

    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
}

int main(){
    ll n;
    cin >> n;

    for(ll i=1;i<=n;i++)
        cin >> C[i];
    for(ll i=1,v,u; i<n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    ll ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}
