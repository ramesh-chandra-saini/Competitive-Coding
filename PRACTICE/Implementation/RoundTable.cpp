/*
    ramesh chandra
    national institute of technology karnataka surathkal
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000000+5][2];
int lastUnPicked=0;
int pick(int arr[],int idx,int size){

    if(idx>=size) return 0;//invalid case
    else {
            int a=(dp[idx][0] != -1)? dp[idx][0]:dp[idx][0]=arr[idx]+pick(arr,idx+1,size);//don't skip next one
            int b=(dp[idx][1]!=-1)?dp[idx][1]:dp[idx][1]=arr[idx]+pick(arr,idx+2,size);//skip next one
            if(a<b) return a;
            else{ lastUnPicked=max(lastUnPicked,idx+1);return b;} //return minimum to final ans
    }
}
int main(){

    int n;   cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++)dp[i][0]=dp[i][1]=-1; //dp intialization
    int ans=pick(arr,0,n);        //choosing first one
    for(int i=0;i<n;i++) dp[i][0]=dp[i][1]=-1;
    lastUnPicked=0; //skipping first one
    int ans2=pick(arr,1,n);//choosing second one
    //check necessary condition if last one is not picked then first and last wiint be two adjacent unpicked take care that case too
    if(lastUnPicked == n-1 && n!=1 ) ans2+=min(arr[0],arr[n-1]);
    cout<<min(ans,ans)<<endl;//final ans to online judge
    return 0;
}
