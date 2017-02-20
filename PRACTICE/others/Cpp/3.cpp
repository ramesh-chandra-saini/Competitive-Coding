/*

    Ramesh Chandra
    NITK
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k,ct=0; cin >> n >> k; int arr[n+2]; for(int i=0;i<n;i++) cin >> arr[i] , ct+=!arr[i];
    if(k>=ct){
        cout << n << endl; for(int i=0;i<n;i++) cout<<(arr[i]||1)<<" "; cout<<endl;
    } else if(k==0){
        int ans=0; for(int i=0,ct=0;i<n;i++){ if(arr[i]) ct++; else ct=0; ans=max(ans,ct);}
                 cout << ans << endl; for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
    }else{
        for(int i=n;i>0;i--) arr[i]=arr[i-1]; arr[n+1]=0; arr[0]=0;
        int dp[n+2]; dp[0]=0;
        for(int i=0;i<n+2;i++) dp[i]=dp[i-1]+arr[i];
        vector<int> zeroIdx; zeroIdx.clear();
        for(int i=0;i<n+2;i++)  if(arr[i] == 0) zeroIdx.push_back(i);
        int idx=0,mx1=0;
        for(int i=k+1;i<zeroIdx.size();i++){
            int total1 = dp[ zeroIdx[i]-1 ] - dp[ zeroIdx[i-k-1] ]+k;
            if(mx1 < total1){

                idx=zeroIdx[i]-1; mx1=total1;
            }
        }
        for(int i=idx;k;i--){
            if(arr[i]==0){ arr[i]=1; k--; }
        }
        int ans=0; for(int i=1,ct=0;i<=n;i++){ if(arr[i]) ct++; else ct=0; ans=max(ans,ct);}
                 cout << ans << endl; for(int i=1;i<=n;i++) cout<<arr[i]<<" "; cout<<endl;
    }

    return 0;
}
