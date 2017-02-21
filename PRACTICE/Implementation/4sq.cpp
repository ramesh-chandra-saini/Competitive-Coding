#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t; cin >> t;
    while(t--){
        ll N,Q,P; cin >> N >> Q >> P;
        vector<ll> arr(N+1);
        for(int i=1;i<=N;i++)
            cin >> arr[i];
        while(Q--){
            ll type; cin >> type;
            if(type==1){
                ll id,val; cin >> id >> val;
                arr[id]=val;
            }else{
                ll L,R; cin >> L >> R;
                ll prod = 1LL;
                for(ll i=L;i<=R;i++)
                    prod*=arr[i];
                for(ll a=0;b<P;a++){
                    for(ll b=0;b<P;b++){
                        for(ll c=0;c<P;c++){

                        }
                    }
                }


            }
        }
    }
    return 0;
}
