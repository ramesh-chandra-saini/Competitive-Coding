#include<bits/stdc++.h>
using namespace std;
#define MAX pow(2,61)
long long int dp[300005];

int main(){

    //cout<<MAX<<endl;
    long long int n;

    scanf("%lld",&n);

    long long int P[n+1];

    for(long long int i=1;i<=n;i++)
        scanf("%lld",&P[i]);

    long long int A[n+1];

    for(long long int i=1;i<=n;i++)
        scanf("%lld",&A[i]);

    long long int H[n+1];
    for(long long int i=1;i<=n;i++)
        scanf("%lld",&H[i]);


    long long int ans=MAX,mn=MAX;
    memset(dp,MAX,sizeof(dp));

    dp[1]=A[1];
    for(long long int i=2;i<=n;i++){

        mn=MAX;
        for(long long int j=1;j<i;j++){

            if(P[j]<P[i])
                mn=min(mn,dp[j]+(H[j]-H[i])*(H[j]-H[i])+A[i]);
        }
        dp[i]=mn;
    }
   // for(long long int i=0;i<=n;i++)cout<<dp[i]<<" "; cout<<endl;
    printf("%lld\n",dp[n]);
        return 0;
}
