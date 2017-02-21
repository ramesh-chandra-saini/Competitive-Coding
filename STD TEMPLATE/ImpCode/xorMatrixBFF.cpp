#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    freopen("c.txt","r",stdin);
    freopen("b.txt","w",stdout);
             ll n,m; cin >> n >> m;
         vector<ll> arr(n),prev(n); for(int i=0;i<n;i++) cin >> arr[i];
         for(int i=1;i<m;i++){
             prev=arr;
             for(int j=0;j<n;j++)
                 arr[j]=prev[j]^prev[(j+1)%n];
         }
         for(int i=0;i<n;i++)
             cout<<arr[i]<<" "; cout<<endl;
     return 0;
 }
