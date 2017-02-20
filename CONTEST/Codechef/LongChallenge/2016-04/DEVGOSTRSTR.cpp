#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
void nextString(char A[] , ll __A,ll n){
    char c = 'a'+(__A); A[0]++;
    for(ll i=0;i<n;i++){
        if(A[i]<c ) return;
        else A[i]='a',A[i+1]++;
    }
}
ll Hamming(char A[], char B[] , ll l){
    ll ans=0;
    for(ll i=0;i<l;i++)
        if(A[i]!=B[i]) ans++;//cout<<ans<<"  ";
    return ans;
}
ll AP(char A[],ll l){
    for(ll i=0;i<l;i++){
        for(ll j=0;j<l;j++){
            ll I = i,J=j,K; K=2*J-I; //cout<<"("<<I<<","<<J<<","<<K<<")  ";
            if( I!=J && I!=K && A[I] == A[J] && A[I] == A[K]) return 0;
        }
    }//  cout<<flag<<" ";
    return 1;
}
int main(){
    ll t,i; scanf("%lld",&t);
    while(t--){
    ll A,K; scanf("%lld%lld",&A,&K);
    char s[51]; scanf("%s",s); ll l = strlen(s); cout<<l<<endl;
    char t[51]; for(i=0;i<l;i++) t[i]='a';
    ll N = pow(A,l);  ll ans = 0LL;
    for( i =0 ;i < N ; i++){ cout<<t<<" ";
        if(Hamming(s,t,l)<=K && AP(t,l)) ans++;//cout<<"YES ";
        nextString(t,A,l);   //cout<<endl;
        ans%=MOD;
    }
    printf("%lld\n",(ans%MOD));
    }
    return 0;
}
