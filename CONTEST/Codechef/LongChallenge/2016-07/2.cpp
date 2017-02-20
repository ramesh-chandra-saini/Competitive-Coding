#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INT_MAX (1LL<<60)
#define INT_MIN -(1LL<<60)
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string str; cin >> str;str.insert(str.begin(),'1'); str.insert(str.end(),'1'); //cout<<str<<endl;
        ll pos[n+2]; pos[0]=INT_MIN;for(ll i=1;i<=n;i++) cin >> pos[i];pos[n+1]=INT_MAX;
        ll leftPolIndex=0,rightPolIndex=0,currNewIndex=0;
        ll ans=0;
        while(currNewIndex<(n+1)){
            currNewIndex++;
            while(str[currNewIndex]=='0') currNewIndex++;//cout<<currNewIndex<<"-->";cout<<endl;
            leftPolIndex=rightPolIndex,rightPolIndex=currNewIndex;
            ll currValue=INT_MAX;
            for(ll i=leftPolIndex;i<rightPolIndex;i++){
                currValue=min(currValue,pos[i]-pos[leftPolIndex]+pos[rightPolIndex]-pos[i+1]);
            }
            ans+=currValue;
        }
        cout<<ans<<endl;
    }
    return 0;
}
