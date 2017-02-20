/*
*   RAMESH CHANDRA  , 22 MARCH 2016
*   NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;

int dp[200000+5][3];//DP TO HOLD SOLVED ALNSWER IN ADVANCE
int pick(int arr[],int stidx,int endidx,int size){
    if(endidx>=size) return 0;//BASE CASE
    else{//CHECK IS ALREADY CALCULATED THEN RETURN ANS FROM DP ELSE CALCULATE , STORE AND RETURN
        return min(

              (  dp[stidx+1][0] != -1)? dp[stidx+1][0] :
                                    dp[stidx+1][0]=arr[stidx]+pick(arr,stidx+1,endidx+1,size),
            min(

              (dp[stidx+1][1] != -1)? dp[stidx+1][1] :
                      dp[stidx+1][1]=arr[stidx+1]+pick(arr,stidx+2,endidx+2,size),

              (dp[stidx+1][2] != -1)? dp[stidx+1][2] :
                    dp[stidx+1][2]=arr[stidx+2]+pick(arr,stidx+3,endidx+3,size)
            )
        );
    }
}
int main(){

    for(int i=0;i<200000+5;i++)//INTIALISE DP TO CHECK WHETHER DP IS UPDATED OR NOT
        dp[i][0]=dp[i][1]=dp[i][2]=-1;
    int n;  scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)//TAKE INPUT AS NUMBER OF MINUTE REQUIRED AN EVENT
        cin >>arr[i];
    printf("%d\n",pick(arr,0,2,n));//PRINT FINAL ANS TO JUDGE
}
