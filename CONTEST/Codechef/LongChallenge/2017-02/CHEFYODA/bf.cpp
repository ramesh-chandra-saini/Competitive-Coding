#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define CHEF true
#define YODA false
ll fact(ll k){
    return (k<1LL)?1LL:k*fact(k-1LL);
}
int main(){
    ll T; cin >> T;
    vector<long double> vec(1000006,0);
    for(ll i=1;i<1000006;i++)
        vec[i]=vec[i-1]+log2(i);

    while(T--){
        ll N,M,P,K; cin >> N >> M >> P >> K;

        bool hvGame   =  (N%2==1 && M%2==1)?YODA:CHEF;
        bool diagGame =  (N%2==0 && M%2==0)?CHEF:YODA;

        if(hvGame == CHEF && diagGame == CHEF){
                if(P==0)
                    printf("1\n");
                else
                    printf("1\n");
        }else if(hvGame == YODA && diagGame == YODA){
                if(P==0)
                    printf("1\n");
                else
                    printf("0\n");
        }else{
            ll ans = 0;
            for(ll i=P;i<=K;i++)
                ans+=fact(K)/(fact(i)*fact(K-i));
            long double fans= ans;
            for(ll i=1;i<=K;i++)
                fans*=0.5;
            printf("%.18Lf\n",fans);
        }

    }
    return 0;
}
