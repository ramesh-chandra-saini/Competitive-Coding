#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
void print(char s[],ll L){
    for(ll i=0;i<L;i++) printf("%c",s[i]);  printf("\n");
}
bool Hamming(char A[],char B[],ll L,ll K){
    ll H=0;
    for(ll i=0;i<L;i++)
        if(A[i]!=B[i]) {++H; if(H>K)return false;};
    return true;
}
void nextStr(char s[],ll L, ll A){
    char c = 'a'+A; s[0]++;
    for(ll i=0;i<L;i++){
        if(s[i]<c) return ;
        else {s[i]='a';++s[i+1];}
    } return;
}
bool AP(char s[],ll L){
    for(ll i=0;i<L;i++){
        for(ll j=i+1;j<L;j++){
            ll k = 2*j-i;
            if(k<L && i!=j && i!=k && j!=k && s[i]==s[j] && s[i]==s[k] && s[j]==s[k]) return false;
        }
    } return true;
}
int main(){
    //cout<<pow(3,12)*50<<endl;
    ll T,A,K,N,L,ans; scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&A,&K);char s[51],t[51];
        scanf("%s",s); L=strlen(s); //print(s,L);  printf("\n");
       N=pow(A,L);ans=0LL;//printf("%lld %lld  ",L,N);
       strcpy(t,s); //for(ll i=0;i<L;i++) t[i]='a'; //print(t,L);
       for(ll i=0;i<N;i++){ //print(t,L);
           if(Hamming(s,t,L,K) && AP(t,L) ) ans++;
           if(ans>=MOD)ans%=MOD;
           nextStr(t,L,A);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
