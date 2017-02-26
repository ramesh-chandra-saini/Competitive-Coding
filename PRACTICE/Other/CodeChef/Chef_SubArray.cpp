#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> vec_op(vector<ll>A,vector<ll>B,ll sign=1){
    for(ll i=0;i<A.size();i++)
        A[i]+=sign*B[i];
    return A;
}
vector<ll> get_bits(ll N,vector<ll> bits = vector<ll>(64)){
    for(ll i=0;i<64;i++,N/=2)
        bits[i]=N%2;
    return bits;
}
ll cal_K(vector<ll>bits,ll ans = 0){
    for(ll i=bits.size()-1;i>=0;i--)
        ans=ans*2LL+(bits[i]>=1);
    return ans;
}
int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N,K;
        cin >> N >> K;
        ll arr[N+1];
        for(ll i=1;i<=N;i++)
            cin >> arr[i];
        ll ans = 0,curr_K=0;
        vector<vector<ll> > bit_count(N+1,vector<ll>(64,0));
        for(ll i=1;i<=N;i++)
            bit_count[i]=vec_op(bit_count[i-1],get_bits(arr[i]));
        for(ll i=1,j=1;i<=N && j<=N;i++){
            j=max(i,j),curr_K=cal_K(vec_op(bit_count[j],bit_count[i-1],-1));
            while(curr_K<K && j<N)
                j++,curr_K=cal_K(vec_op(bit_count[j],bit_count[i-1],-1));
            ans+=(curr_K>=K)?N-j+1:0;
        }
        cout<<ans<<endl;
    }
}
