#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t; while(t--){
        long long  n,b,m; cin >> n >> b >>m;
        long long ans=0LL;

        while(n){
           long long task =(n+1LL)/2LL;
           ans+=task*m+b;
          n-=task;
          m*=2LL;

        }
        ans-=b;
        (ans>0)? cout<<ans<<endl:cout<<ans<<endl;

    } return 0;
}

