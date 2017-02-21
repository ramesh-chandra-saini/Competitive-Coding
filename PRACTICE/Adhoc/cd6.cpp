#include<bits/stdc++.h>
using namespace std;

#define s(x) scanf("%d",&x)
int main(){

    int n,t,k;
   scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        int arr[n],v[n];
        for(int i=0;i<n;i++)
            scanf("%d%d",&arr[i],&v[i]);
        for(int i=1;i<=n;i++){

            for(int j=1;j<=k;j++){

                if(arr[i-1]<j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1]]+v[i-1]);
            }
        }
        for(int i=0;i<=n;cout<<endl,i++)
            for(int j=0;j<=k;j++)
                cout<<dp[i][j]<<" ";
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
