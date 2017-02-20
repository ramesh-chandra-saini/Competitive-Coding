#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    string ans="-1";
    if(n>2){
        int diff = arr[n-1]-arr[n-2];
        if(diff>0){
            if(arr[n-1]!=15)
                ans="UP";
            else
                ans="DOWN";
        }else if(diff<0){
            if(arr[n-1]!=0)
                ans="DOWN";
            else
                ans="UP";
        }
    }
    cout<<ans<<endl;
}
