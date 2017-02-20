#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll N,ll base){
    while(N){
        if(N%base!=1)
            return false;
        N/=base;
    }
    return true;
}

int main(){

  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
    ll t;cin >> t;
    for(ll T=1;T<=t;T++){
        ll N;cin >> N;
        ll ans = INT_MAX;
        for(ll base=2;base*base<=N;base++){
            //cout<<base<<" ";
            if(check(N,base)==true){
                ans = base;
                break;
            }
        }
        ll sq = sqrt(N-1);
        if(ans==INT_MAX){
                ans=N-1;

        }

        //cout<<N<<" "<<ans<<endl;
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }


    return 0;

}

