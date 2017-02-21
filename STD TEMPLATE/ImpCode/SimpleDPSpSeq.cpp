/*
Only for Partial Solution............
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000+2];
vector<vector<int> > c;
int Solve(int n ,int arr[],  int prev, int curr, int K){

    if(curr>=n) return 0;
    return
        (abs(arr[prev]-arr[curr])<=K) ?
            max(
                  (dp[curr][curr+1]!=-1)?dp[curr][curr+1]: dp[curr][curr+1]=1+Solve(n,arr,curr,curr+1,K),//selecting curr item
                    (dp[prev][curr+1]!=-1)?dp[prev][curr+1]: dp[prev][curr+1]=Solve(n,arr,prev,curr+1,K) //skipping curr item
            )
            :
            (dp[prev][curr+1]!=-1)?dp[prev][curr+1]: dp[prev][curr+1]=Solve(n,arr,prev,curr+1,K);
}
int main(){

    int n,k;
    scanf("%d%d",&n,&k); c=vector<vector<int> > vector(n);//,vector<int>(n));
    int arr[n+1];
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    if(n==1) printf("1\n");
    else{
        arr[0]=arr[1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n+1;j++){
                dp[i][j]=-1;
            }
        }
        int ans=Solve(n+1,arr,0,1,k);
        arr[0]=arr[2];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        int ans2=Solve(n+1,arr,0,2,k);
        printf("%d\n",max(ans,ans2));
    }
    return 0;
}
