#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Ai 1000000000000000000
map<ll,ll> mp1;
pair<ll,ll> vec1[1000006];
int main() {
    clock_t runtime = clock();
    ll T; cin >> T;//scanf("%lld\n",&T);
    assert(T>=1 && T<=500);
    while(T--){
        map<ll,ll> mp; mp.clear();
        ll N; cin >> N; //scanf("%lld\n",&N);
        assert(N>=1 && N<=1000000);
        for(ll i=0,x;i<N;i++){
            cin >> x ; //scanf("%lld",&x);
            assert(x>=-Ai && x<=Ai);
            ++mp[x];
        }
        ll size = 0;
        vector< pair<ll,ll> > vec; vec.clear();
        for(map<ll,ll>::iterator it = mp.begin();it != mp.end();++it)
            vec.push_back(make_pair(-it->second,it->first));
        sort(vec.begin(),vec.end());
        for(ll i=0;i<vec.size();i++)
            cout << vec[i].second<<" ";
//            printf("%lld ",vec[i].second);
        set<ll> st; st.clear();
        for(ll i=0;i<vec.size();i++)
            st.insert(vec[i].second);
        assert(vec.size()==st.size());
  cout<<endl;
        //printf("\n");
    }
    runtime = clock()-runtime;
   // cout<<(float(runtime)/CLOCKS_PER_SEC)<<endl;
    return 0;
}
