/*
    log and Expo
    No hard work
*/
#include<bits/stdc++.h>
using namespace std;
#define CHEF true
#define YODA false
int main(){
    int T; cin >> T;
    vector<long double> fact(1000006,0);
    for(int i=1;i<1000006;i++)
        fact[i]=fact[i-1]+log(i);
    while(T--){
        int N,M,P,K; cin >> N >> M >> P >> K;
        bool hvGame   =  (N%2==1 && M%2==1)?YODA:CHEF;
        bool diagGame =  (N%2==0 && M%2==0)?CHEF:YODA;
        if(hvGame == CHEF && diagGame == CHEF){
                (P==0)?printf("1\n"):printf("1\n");
        }else if(hvGame == YODA && diagGame == YODA){
                (P==0)?printf("1\n"):printf("0\n");
        }else{
            long double ans = 0;
            long double inv = K*log(2);
            for(int i=P;i<=K;i++)
                ans+= exp(fact[K]-fact[i]-fact[K-i]-inv);
            printf("%.30Lf\n",ans);
        }

    }
    return 0;
}
