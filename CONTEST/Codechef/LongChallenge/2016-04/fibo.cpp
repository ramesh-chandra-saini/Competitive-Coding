#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define __M 1000000007
ll ans = 0LL;
void  multiply(long long int F[][2],long long int M[][2]){
    long long int x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
    long long int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
    long long int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
    long long int w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
    F[0][0]=x%__M;F[0][1]=y%__M; F[1][0]=z%__M;F[1][1]=w%__M;
}
void  POWER(long long int F[][2],long long int N,long long int M[][2]){
    if(N==0|| N==1) return;
    POWER(F,N/2,M);
    multiply(F,F);
    if(N%2){
       long long int M[2][2]={{1,1},{1,0}};
        multiply(F,M);
    }
}
long long int  fib(long long int N){
    long long int F[2][2]={{1,1},{1,0}};
     long long int M[2][2]={{1,1},{1,0}};
    if(N==0) return 0;
    else if(N==1) return 1;
    else  POWER(F,N-1,M);
    return F[0][0];
}
void calSum(ll A[],ll I,ll J){
    ll sum=0LL; vector<ll> set; set.clear();
    for(ll i=I;i<=J;i++){sum+=A[i]; set.push_back(A[i]);}
    ll n=set.size();
     // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];
    bool dp[sum+1][n+1]; memset(dp,0,sizeof(dp));
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++){
        for (int j = 1; j <= n; j++){
            subset[i][j] = subset[i][j-1];
            if (i >= set[j-1]){
                subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
                dp[i][j]=subset[i - set[j-1]][j-1];
            }
        }
     }
     ll ANS=0LL;/*
      for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
     } cout<<endl;*/
     for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]){ cout<<i<<" ";
                ANS=(ANS+fib(i))%__M;
            }
        }
     } cout<<endl;
     printf("%lld\n",ANS);
}
void __calSum(ll A[],ll x,ll y){
    vector<int>sum; sum.clear(); sum.push_back(A[x]);
    for(ll i = x+1;i<=y;i++){

        ll s=sum.size();
        for(ll j=0;j<s;j++) sum.push_back(sum[j]);
        for(ll j=s;j<sum.size();j++) sum[j]+=A[i];
        sum.push_back(A[i]);
    }
    ll ans=0LL;
    for(ll i=0;i<sum.size();i++){
        ans=(ans+fib(sum[i]))%__M;
    }
    printf("%lld\n",ans);
}
int main(){
    ll N,Q; scanf("%lld%lld",&N,&Q);
    ll A[N+5];for(ll i=1;i<=N;i++) scanf("%lld",&A[i]);
    char c; ll x,y;
    while(Q--){
        cin >> c >> x >> y;
        ///printf("%c %lld %lld\n",c,x,y);
        if(c=='C') A[x]=y;
        else{
           __calSum(A,x,y);
        }
    }return 0;
}
