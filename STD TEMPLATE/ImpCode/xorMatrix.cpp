#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
        ll n,m; cin >> n >> m;
        vector<ll> arr(n); for(ll i=0;i<n;i++)  cin >> arr[i];
        m--;  vector<ll> prev(arr);
        if(m==0){
            //nothing to do
        }else if(m==1){
            for(int i=0;i<n;i++)
                arr[i]=prev[i]^prev[(i+1)%n];
        }else if(m%2==0)){
            for(ll i=0;i<n;i++)
                arr[i] = prev[i]^prev[(i+m)%n];
        }
        else {
            for(ll i=0;i<n;i++)
                arr[i]= prev[i] ^ prev[(i+1)%n]^prev[(n+i+m-1)%n]^prev[(i+m)%n];
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" "; cout<<endl;
   return 0;
}
