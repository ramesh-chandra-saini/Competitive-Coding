/*
*   RAMESH CHANDRA  , 22 MARCH 2016
*   NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;


int dp[200000+5][2];//DP TO HOLD SOLVED ALNSWER IN ADVANCE
int pick(int arr[],int idx,int size){
    if(idx>=size) return 0;//BASE CASE
    else{//CHECK IS ALREADY CALCULATED THEN RETURN ANS FROM DP ELSE CALCULATE , STORE AND RETURN
        return max(
            //take one in a row
            (dp[idx][0] != INT_MIN) ? dp[idx][0]: dp[idx][0]=arr[idx]+pick(arr,idx+2,size),
            //take two in a row
            (dp[idx][1] !=INT_MIN ) ? dp[idx][1]: dp[idx][1]= (arr[idx]+( (idx+1 >= size)?0:arr[idx+1] )+pick(arr,idx+3,size) )
        );
    }
}
int main(){

    int n;  scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)//TAKE INPUT AS price of player  REQUIRED for A match
        cin >>arr[i];
    for(int i=0;i<200000+5;i++)//INTIALISE DP TO CHECK WHETHER DP IS UPDATED OR NOT
        dp[i][0]=dp[i][1]=INT_MIN;
    int ans=pick(arr,0,n); //taking first day
    for(int i=0;i<200000+5;i++)//INTIALISE DP TO CHECK WHETHER DP IS UPDATED OR NOT
        dp[i][0]=dp[i][1]=INT_MIN;
    int ans2=pick(arr,1,n);//skipping first day

    printf("%d\n",max(ans2,ans) );//PRINT FINAL ANS TO JUDGE
}
