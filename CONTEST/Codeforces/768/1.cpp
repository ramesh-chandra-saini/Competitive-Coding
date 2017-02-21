#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int mn = INT_MAX,mx = INT_MIN;
    int a[n];
     for(int i=0;i<n;i++) cin >> a[i],mn = min(mn,a[i]),mx = max(mx,a[i]);
     int ans = 0;
     for(int i=0;i<n;i++)
        ans+=(a[i]>mn && a[i]<mx);
    cout<<ans<<endl;
}
