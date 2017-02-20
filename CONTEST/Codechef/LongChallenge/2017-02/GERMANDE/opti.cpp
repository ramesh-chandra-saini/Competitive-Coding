#include<bits/stdc++.h>
using namespace std;
#define ll long long int

enum winner { CHEF,YODA } ;

ll fact(ll k){
    return (k<1LL)?1LL:k*fact(k-1LL);
}
int main(){
    ll T; cin >> T;
    while(T--){
        ll N,M,P,K; cin >> N >> M >> P >> K;
        winner hvGame   =  (N%2==1 && M%2==1)?YODA:CHEF;
        winner diagGame =  (N%2==0 && M%2==0)?CHEF:YODA;
        if(hvGame == CHEF && diagGame == CHEF){
                (P==0)?printf("0\n"):printf("1\n");
        }else if(hvGame == YODA && diagGame == YODA){
                (P==0)?printf("1\n"):printf("0\n");
        }else{
            ll ans = 0;
            for(ll i=P;i<=K;i++)// sum of kCp+kC(p+1)......+kCk
                ans+=fact(K)/(fact(i)*fact(K-i));
            double fans= ans;
            for(ll i=1;i<=K;i++)//divide ans/2^k
                fans*=0.5;
            printf("%.9lf\n",fans);
        }
    }
    return 0;
}
