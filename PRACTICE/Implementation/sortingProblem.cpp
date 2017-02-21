#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Ai 1000000000000000000
int main() {
    ll T; scanf("%lld\n",&T);
    assert(T>=1 && T<=5);
    while(T--){
        map<ll,ll> mp;mp.clear();
        ll N; scanf("%lld\n",&N);
        assert(N>=1 && T<=1000000);
        for(ll i=0,x;i<N;i++){
            scanf("%lld",&x);
            assert(x>=-Ai && x<=Ai);
            ++mp[x];        
        }
        vector<pair<ll,ll> > vec; vec.clear();
        for(map<ll,ll>::iterator it = mp.begin();it != mp.end();++it)
            vec.push_back(make_pair(-it->second,it->first));
        sort(vec.begin(),vec.end());
        for(ll i=0;i<vec.size();i++)
            printf("%lld ",vec[i].second);
        set<ll> st; st.clear();
        for(ll i=0;i<vec.size();i++)
            st.insert(vec[i].second);
        assert(vec.size()==st.size());
        printf("\n");
    }
    return 0;
}

