#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i=0LL;i<n;i++) 
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    bool ans=true;    
    ll x=arr[n-1]-arr[0];
    if(x%2){
        ans=false;
    }else{
        x/=2LL;
        ll I=0LL,J=n-1LL;
        while(I<J){
        arr[I]+=x, arr[J]-=x;
        I++, J--;
        }
        ll equal=arr[0];
        for(ll i=0;i<n;i++){
            if(arr[i]!=equal){
                ans=false;
                break;  
              }
        }
     }
    (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}
