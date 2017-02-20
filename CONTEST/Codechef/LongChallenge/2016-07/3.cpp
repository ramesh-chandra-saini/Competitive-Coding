#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INT_MAX (1LL<<60)
#define INT_MIN -(1LL<<60)

ll getMaxAns(vector<ll>& A, vector<ll>& B, ll n, ll target){
    vector<ll> base(A);
    vector<ll> visitB(n+2,false);
    for(int i=1;i<=n;i++){
        if(!visitB[i-1]) base[i]+=B[i-1],visitB[i-1]=true;//you have to include this....otherwise this will not be included into anyone
        if(!visitB[i] && base[i]+B[i] == target) base[i]+=B[i],visitB[i]=true;
        else if( !visitB[i+1] && base[i]+B[i+1]==target) base[i]+=B[i+1],visitB[i+1]=true;
        else if( !visitB[i] && !visitB[i+1] && base[i]+B[i]+B[i+1] == target) base[i]+=B[i]+B[i+1],visitB[i]=visitB[i+1]=true;
        else ;
    }

    for(int i=1;i<=n;i++){
        if(!visitB[i]) return -1;
    }
    for(int i=1;i<=n;i++){
        if(base[i]!=target) return -1;
    }
    return target;
}
ll solveProblem(vector<ll>&A,vector<ll>& B,ll n){

    ll maxAns=-1;
    // 4-Possible Target
    //A[1]
    maxAns=max(maxAns,getMaxAns(A,B,n,A[1]));
    //A[1]+B[1]
    maxAns=max(maxAns,getMaxAns(A,B,n,A[1]+B[1]));
    //A[1]+B[2]
    maxAns=max(maxAns,getMaxAns(A,B,n,A[1]+B[2]));
    //A[1]+B[1]+B[2]
    maxAns=max(maxAns,getMaxAns(A,B,n,A[1]+B[1]+B[2]));
    return maxAns;
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n ;
        vector<ll> B(n+2); B[0]=0;for(ll i=1;i<=n;i++) cin >> B[i]; B[n+1]=0;
        vector<ll> A(n+2); for(ll i=1;i<=n;i++) cin >> A[i];
        if(n==1) cout<<(A[1]+B[1])<<endl;
        else cout<<solveProblem(A,B,n)<<endl;
    }
    return 0;
}
