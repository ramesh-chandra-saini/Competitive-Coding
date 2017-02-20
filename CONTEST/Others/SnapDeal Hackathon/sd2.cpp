#include<bits/stdc++.h>
using namespace std;

#define mod  1000000007
#define ll long long int

#define D 0
#define S 1
#define U 2

ll A[2501][2501];
ll dp[2501][2501][3];

int main(){

    memset(A,0,sizeof(A));
    memset(dp,0,sizeof(dp));

    ll N,M;
    cin >> N >> M;

    for(ll i=1;i<=N;i++)
        for(ll j=1;j<=M;j++)
            cin >> A[i][j];

    if(N==1){

        ll ans=1;
        for(ll j=1;j<=M;j++)
        if(A[1][j])ans=(ans*A[1][j])%mod;
        cout<<ans<<endl;
        return 0;
    }

    ll side=1;
    for(int j=1;j<=M;j++){
        if(A[1][j]){

            side=(A[1][j]*side)%mod;
            dp[1][j][S]=side;
        }
    }
    ll up=1;
    for(int i=2;i<=N;i++){

        if(A[i][1]){

            up=(A[i][1]*up)%mod;
            dp[i][1][U]=up;
        }
    }


    ll UP=0,DIAG=0,SIDE=0,__M=1;

    for(ll i=2;i<=N;i++){

        for(ll j=2;j<=M;j++){

            UP=0LL;DIAG=0LL;SIDE=0LL;__M=1LL;
            if(A[i][j]) __M=A[i][j];

            if(A[i-1][j-1]==0){
                DIAG=dp[i-1][j-1][D]*__M;
            }
            else{

                DIAG=(dp[i-1][j-1][U]+dp[i-1][j-1][D]+dp[i-1][j-1][S])*__M;
            }

            if(A[i-1][j]==0){

                UP=dp[i-1][j][U]*__M;
            }
            else{

                UP=(dp[i-1][j][U]+dp[i-1][j][D]+dp[i-1][j][S])*__M;
            }

            if(A[i][j-1]==0){

                SIDE=dp[i][j-1][S]*__M;
            }
            else{

                SIDE=(dp[i][j-1][S]+dp[i][j-1][U]+dp[i][j-1][D])*__M;
            }
            dp[i][j][U]=UP%mod;
            dp[i][j][D]=DIAG%mod;
            dp[i][j][S]=SIDE%mod;
        }
    }
    /*
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++)
            cout<<"("<<dp[i][j][0]<<","<<dp[i][j][1]<<","<<dp[i][j][2]<<")  ";
        cout<<endl;
    }
    cout<<N<<"X"<<M<<endl;
    */
    ll ANS=0;
    if(dp[N][M][S]) ANS=(ANS+dp[N][M][S])%mod;
    if(dp[N][M][U]) ANS=(ANS+dp[N][M][U])%mod;
    if(dp[N][M][D]) ANS=(ANS+dp[N][M][D])%mod;
    cout<<ANS<<endl;
    return 0;
}
