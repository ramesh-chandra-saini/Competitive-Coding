#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mat[2][2]={{1LL,1LL},{1LL,0LL}};
ll unit[2][2]={{1LL,0LL},{0LL,1LL}};

vector<vector<ll> > arr2vec(ll arr[2][2]){
    vector<vector<ll> > vec(2,vector<ll>(2,0));
    for(ll i=0;i<2;i++)
        for(ll j=0;j<2;j++)
            vec[i][j]=arr[i][j];
    return vec;
}

vector<vector<ll> > mult(vector<vector<ll> > A,vector<vector<ll> > B,ll mod){
    vector<vector<ll> > C(2,vector<ll>(2,0));
    for(ll i=0;i<2;i++)
        for(ll j=0;j<2;j++)
            for(ll k=0;k<2;k++)
                C[i][j]=(C[i][j]+(A[i][k]*B[k][j])%mod)%mod;
    return C;
}
ll power(ll power,ll mod){
    vector<vector<ll> > ans = arr2vec(unit);
    vector<vector<ll> > N = arr2vec(mat);
    for(;power;power/=2LL,N=mult(N,N,mod))
        ans = (power%2)?mult(ans,N,mod):ans;
    return (ans[0][0]+ans[0][1])%mod;
}
int main(){
    //freopen("in.txt","r",stdin);
    ll T; scanf("%lld",&T);
    while(T--){
        ll A,N,M; scanf("%lld%lld%lld",&A,&N,&M);
        if(A==0){
            printf("0\n");
        }else{
            ll r = 1LL,a=A; while(a) r*=10LL,a/=10LL;
            mat[0][0]=r;
            printf("%lld\n",(power(N-1,M)*A)%M);
        }
    }
    return 0;
}
