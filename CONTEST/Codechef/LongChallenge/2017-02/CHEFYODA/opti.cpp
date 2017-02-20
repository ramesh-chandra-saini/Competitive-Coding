#include<bits/stdc++.h>
using namespace std;
#define CHEF true
#define YODA false
int main(){
    int  T; cin >> T;
    long double arr[1000006];
    arr[0] = (long double)(1);
    for(int i=1;i<=min(1000,K);i++)
                arr[i]=arr[i-1]*0.5;
    while(T--){
        int N,M,P,K; cin >> N >> M >> P >> K;
        bool hvGame   =  (N%2==1 && M%2==1)?YODA:CHEF;
        bool diagGame =  (N%2==0 && M%2==0)?CHEF:YODA;
        if(hvGame == CHEF && diagGame == CHEF){
                (P==0)?printf("1\n"):printf("1\n");
        }else if(hvGame == YODA && diagGame == YODA){
                (P==0)?printf("1\n"):printf("0\n");
        }else{
            long double fans = arr[min(1000,K)]

            (long double)(1);
            for(int i=1;i<=min(1000,K);i++)
                fans*=0.5;
            long double double_fans = (long double)(1);
            for(int i=1001;i<=K;i++)
                double_fans*=0.5;

            long double ans = (P==0)?(long double)(0):fans*double_fans;
            long double prev = fans;
            long double A=(long double)K,B=(long double)(1);
            for(int i=1;i<=P-1;i++,A--,B++)
                prev = (prev/B)*A,
                ans+=prev*double_fans;
            printf("%.18Lf\n",double(1)-ans);
        }
    }
    return 0;
}
