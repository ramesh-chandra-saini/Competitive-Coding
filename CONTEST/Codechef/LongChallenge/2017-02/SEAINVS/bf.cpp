#include<bits/stdc++.h>
using namespace std;
#define ll long long int
set<vector<ll> > st;
set<vector<ll> > :: iterator it;
void permute(ll P[],ll l,ll r){
    if(l==r){
        vector<ll> temp;temp.clear();
        for(ll i=1;i<=r;i++)
            temp.push_back(P[i]);
        st.insert(temp);
    }else{
        for(ll i=l;i<=r;i++){
            swap(P[l],P[i]);
            permute(P,l+1,r);
            swap(P[i],P[l]);
        }
    }
}
int main(){
    ll T; cin >> T;
    while(T--){
        ll N,M; cin >> N >> M;
        ll P[N+1];

        for(ll i=1;i<=N;i++)
            cin >> P[i];

        while(M--){
            ll l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
            ll S = r1-l1+1;
            ll arr[S+1];
            for(ll i=1;i<=S;i++)
                arr[i] = i;
            st.clear();
            permute(arr,1,S);
            ll ans = 0;
            for(it=st.begin();it!=st.end();++it){
                vector<ll> Q = *it;
                ++ans;
                for(ll i=1;i<=S;i++){
                    if(P[Q[i-1]+l1-1]>=P[i+l2-1]){
                        --ans;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
