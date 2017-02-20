#include<bits/stdc++.h>
using namespace std;

#define mod  1000000007
#define ll long long int

ll A[2505][2505];
ll dp[2505][2505];

int main(){

    memset(A,0,sizeof(A));
    memset(dp,0,sizeof(dp));
    ll N,M;
    scanf("%lld%lld",&N,&M);
    //cin >> N >> M;

    for(ll i=1;i<=N;i++)
        for(ll j=1;j<=M;j++)
            scanf("%lld",&A[i][j])
            //cin >> A[i][j];

    dp[1][1]=A[1][1];

    for(ll j=2;j<=M;j++){

        ll SIDER=0;
        for(ll __j=j-1;__j>=0;__j--)
            SIDER+=dp[1][__j];
        dp[1][j]=(SIDER*A[1][j])%mod;
    }

    for(ll i=2;i<=N;i++){

        ll UP=0;
        for(ll __i=i-1;__i>=0;__i--)
            UP+=dp[__i][1];
        dp[i][1]=(UP*A[i][1])%mod;
    }

    for(ll i=2;i<=N;i++){
        for(ll j=2;j<=M;j++){

                ll U=0;ll S=0; ll D=0;
                for(ll u=i-1;u>=0;u--)
                        U+=dp[u][j];

                for(ll s=j-1;s>=0;s--)
                        S+=dp[i][s];

                for(ll a=i-1,b=j-1; b>=0 && a>=0;a--,b--)
                        D+=dp[a][b];
                //cout<<U<<" "<<S<<" "<<D<<" "<<A[i][j]<<endl;
                dp[i][j]=((U+S+D)*A[i][j])%mod;
         }
    }
    printf("%lld\n",dp[N][M]);
    return 0;
}
