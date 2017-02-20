#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q; cin >> n >> q;
    int arr[n];for(int i=0;i<n;i++) cin >> arr[i];
     sort(arr,arr+n);
    int a=arr[0],b=arr[0];
    for(int i=0,j=n-1;i<j;i++,j--) a=arr[i],b=arr[j];
    while(q--){
        int t; cin >> t;
        if(a<=t && t<=b) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
