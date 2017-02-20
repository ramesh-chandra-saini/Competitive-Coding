#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,n;
    cin >> t;

    while(t--){

        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int ct=1;
        int ans[n];
        ans[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if( (arr[i]>0 && arr[i+1]>0) || (arr[i]<0 && arr[i+1]<0)){
                ct=1;
            }else ct++;
            ans[i]=ct;
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" "; cout<<endl;
    }
    return 0;

}
