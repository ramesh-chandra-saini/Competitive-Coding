#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n; cin >> n;
    set<ll> arr;arr.clear();
    for(ll i=0,val;i<n;i++){
        cin >> val;
        arr.insert(val);
    }
    if(arr.size()>=4) cout<<"NO"<<endl;
    else if(arr.size()<=2) cout<<"YES"<<endl;
    else{
        set<ll>::iterator it=arr.begin();
        ll a=*it;++it;
        ll b=*it;++it;
        ll c=*it;++it;
        if(b-a==c-b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
