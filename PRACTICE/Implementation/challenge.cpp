#include<bits/stdc++.h>
using namespace std;
#define MAX (1LL<<62)
#define ll long long
#define ld long double
int main(){
    ll n,k,d; cin >> n >> K >> D;
    vector<ll> arr(n); for(ll i=0;i<n;i++) cin >> arr[i];

    for(ll a=-100;a<=100;a++){
        for(ll d=-100;d<=100;d++){
            vector<pair<ll,ll> > A(n);
            for(ll i=0;i<n;i++)
                A[i]=make_pair(abs(arr[i]-(a+d*i)),i);
            sort(A.begin(),A.end());
            ll currAttraction = 0,i=0;
            vector<ll> deleted;
            while(!A.empty() && D--)
                deleted.push_back(A.size()),A.pop_back();
            K=2*K;
            for(i=0;i<A.size() && K ;i+){

            }
        }
    }
    return 0;
}
