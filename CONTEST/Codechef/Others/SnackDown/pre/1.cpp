#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];bool ans=false;
        for(int i=0;i<n;i++) cin >> arr[i];
        for(int i=2;i<n;i++){
            if(arr[i]==arr[i-1] && arr[i-1]==arr[i-2]){
                ans=true; break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
