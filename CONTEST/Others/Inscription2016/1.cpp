#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n; cin >> n;
    ll odd = 0,even = 0;
    for(ll i=0,val;i<n;i++){
        cin >> val;
        if(val%2==0) even++;
        else odd++;
    }
    (even>=odd)?cout<<"READY FOR BATTLE"<<endl:cout<<"NOT READY"<<endl;
    return 0;
}
