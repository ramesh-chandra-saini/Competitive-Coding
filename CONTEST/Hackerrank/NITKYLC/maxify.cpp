#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
   cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    int ans= (arr[n-1]*arr[n-2]-arr[0]+arr[n-3]);
    int ans2=(arr[0]*arr[1]-arr[2]+arr[n-1]);
    cout<<max(ans,ans2)<<endl;
}
