#include<bits/stdc++.h>
using namespace std;

int main(){


    int N,i;
    cin >> N;

    int arr[N+2];

    for(i=1;i<=N;i++)
        cin >> arr[i];

    arr[0]=arr[N+1]=INT_MAX;
    int dp[N+2]; memset(dp,0,sizeof(dp));

    //Increasing segment
    for(int i=1;i<=N;){

        if(arr[i]<arr[i+1]){

            int candies=1;

            while(i<=N && arr[i]<arr[i+1]) {
                dp[i]=max(dp[i],candies); i++; candies++;
            }
            dp[i]=max(dp[i],candies);
        }
        else i++;
    }

    //Equal Segment
    for(int i=1;i<=N;){

        if(arr[i]==arr[i+1]){

            while(i<=N && arr[i]==arr[i+1]){
                dp[i]=max(dp[i],1); i++;
            }
            dp[i]=max(dp[i],1);
        }
        else i++;
    }

    for(int i=N;i>=1;){

        if(arr[i]<arr[i-1]){

            int candies=dp[i];

            while(i>1 && arr[i]<arr[i-1]){

                dp[i]=max(dp[i],candies);
                i--;candies++;
            }
            dp[i]=max(dp[i],candies);
        }
        else i--;
    }

    for(int i=1;i<=N;i++) cout<<dp[i]<<" "; cout<<endl;
    long long int ans=0;

    for(int i=1;i<=N;i++){

        ans+=dp[i];
    }

    cout<<ans<<endl;
    return 0;
}
