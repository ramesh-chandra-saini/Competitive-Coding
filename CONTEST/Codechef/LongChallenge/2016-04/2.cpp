#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll t,n; cin >> t;
    while(t--){
        ll R,G,B,K,sum;cin >> R >> G >> B >> K ;
        sum = min(K-1,R) + min(K-1,G) + min(K-1,B) + 1 ;
        cout<<sum<<endl;
    }

    return 0;
}
