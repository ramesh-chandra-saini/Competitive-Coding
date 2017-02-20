/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> segTree(10000000,0);
ll getMax(ll l, ll r, ll L, ll R,ll index){
    if(l>r || r<L || R<l) return INT_MIN;
    if(L<=l&&r<=R) return segTree[index];
    return max(getMax(l,(l+r)/2LL,L,R,2LL*index+1LL),getMax(1LL+(l+r)/2LL,r,L,R,2LL*index+2LL));
}
ll buildSegTree(ll L, ll R, ll index, vector<ll>&arr){
    if(L>R) return INT_MIN;
    if(L==R) return segTree[index]=arr[L];
    return segTree[index]=max(buildSegTree(L,(L+R)/2LL,2LL*index+1LL,arr),buildSegTree(1LL+(L+R)/2LL,R,2LL*index+2,arr));
}
ll MAX(int L,int R,ll N){
   return getMax(0LL,N-1LL,L,R,0LL);
}
bool F(ll i,ll j,vector<ll>&A){
    return(A[i]&A[j])==A[i]||(A[i]&A[j])==A[j];
}
int main(){
    ll n; cin >> n;
    vector<ll>A(n); for(ll i=0;i<n;i++) cin >> A[i];
    buildSegTree(0LL,n-1LL,0LL,A);
    ll ans=0LL;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            ans+=MAX(i,j,n)*F(i,j,A);
    cout<<ans<<endl;
    return 0;
}
