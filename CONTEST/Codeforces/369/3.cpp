#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX (1LL<<62)
int main(){
    //cout<<MAX<<endl;
    ll n,m,k; cin >> n >> m >> k;
    ll color[n+1]; for(ll i=1;i<=n;i++) cin >> color[i];
    ll colorScheme[n+1][m+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> colorScheme[i][j];
        }
    }
    // dp[tree][beauty][color]
    ll dp[n+1][n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=m;k++)
                dp[i][j][k]=MAX;


    return 0;
}
