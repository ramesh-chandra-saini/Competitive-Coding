/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
==============================================================
            #BruteForce
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll preKdiffDigitLeastNumber(ll K){
    ll ans=0LL;for(ll i=1;i<=K;i++) ans=(ans*10+i);
    return ans;
}
int main(){
    ll Q; scanf("%lld",&Q);
    while(Q--){
        ll L,R,K; cin >> L >> R >> K;
        ll ans=0LL; L=max(L,preKdiffDigitLeastNumber(K));
        for(ll i=L;i<=R;i++){
            ll temp=i,kSpecial=0LL;vector<bool>visit(10,false);
            while(temp)visit[temp%10LL]=true,temp/=10LL;
            for(ll k=1;k<=9;k++) kSpecial+=(!(i%k) && visit[k]);
            ans+=(kSpecial>=K);
          //  ((kSpecial>=K)) ? cout<<i<<" ":cout<<"";;
        } //cout<<endl;
        cout<<ans<<endl;
    }
}
