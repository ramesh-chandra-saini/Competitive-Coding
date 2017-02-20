#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll changeBase(ll value){
    ll ans=0LL;
    for(ll i=0LL;value>0LL;value/=10LL,i++)
        ans+=(value%2LL)*pow(2LL,i);
    return ans;
}
int main(){
    vector<ll> myHash(600000LL,0LL);//524287 : 262144;
    ll Q; cin >> Q ; while(Q--){
        char c;
        ll value;
        cin >> c >> value;
        switch(c){
            case '+' :
                myHash[changeBase(value)]++;
            break;
            case '-':
                myHash[changeBase(value)]--;
            break;
            case '?':
                cout<<myHash[changeBase(value)]<<endl;
            break;
        }
    }return 0;
}
