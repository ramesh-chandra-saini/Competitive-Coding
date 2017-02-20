#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void Solve(ll N,ll Sum, ll L,ll R,string &ans){

int main(){
    ll t; cin >> t;
    while(t--){
        ll N,Sum; cin >> N >> Sum ;
       string ans("No");
       if(N==1) ans ="Yes";
       else if((Sum*2LL) % N ==0){
           ll P =(Sum*2LL)/N;
           if(P>2LL && P-2LL>=(N-1LL)){
                ll D = (P-2LL)/(N-1LL);
           }

       }
        cout<<ans<<endl;
    }
}
