#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll arr[n+1];
        for(ll i=0;i<n;i++) cin >> arr[i];
        ll __mx=INT_MIN;
        for(int i=0;i<n;i++)
            __mx=max(arr[i],__mx);
        if(__mx<0) cout<<__mx<<endl; //all are negative
        else{//min sum as 0
            ll sum=0,currLeftSum=0,currRightSum=0;
            ll cummLeft[n+2]; cummLeft[0]=cummLeft[n+1]=0;
            ll cummRight[n+2]; cummRight[0]=cummRight[n+1]=0;
            for(int i=0;i<n;i++){ //maxSumSubArray from Left
                currLeftSum+=arr[i];
                currLeftSum=max(currLeftSum,0LL);
                cummLeft[i+1]=currLeftSum;
            }
            for(int i=n-1;i>=0;i--){ //maxSumSubArray from Right
                currRightSum+=arr[i];
                currRightSum=max(currRightSum,0LL);
                cummRight[i+1]=currRightSum;
            }
            for(int i=1;i<=n;i++){ //check fro maxSum withour removal or with removal also
                sum=max(sum,cummLeft[i]);
                sum=max(sum,cummRight[i]);
                sum=max(sum,cummLeft[i-1]+cummRight[i+1]);
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
