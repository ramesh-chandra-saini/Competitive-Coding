#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,n,arr[100005],curr;

    cin >>t;

    while(t--){

        cin >>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        long long int ans=0,len=0;
        for(int i=0;i<n;){

            for(curr=arr[i],len=0; i<n && curr<=arr[i]; curr=arr[i],len++,i++);
            ans+=(len*(len+1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
