#include<bits/stdc++.h>
using namespace std;
#define M 10000058

bool arr[M+1];
int prime[5761455+10];
void seive(){
    for(int i=0;i<=M;i++)
        arr[i]=true;
    arr[0]=arr[1]=false;
    for(int i=2;i*i<=M;i++){
        if(arr[i]){
            for(int j=i*i;j<=M;j+=i)
                arr[j]=false;
        }
    }
   for(int i=0,j=0;i<=M;i++)
    if(arr[i]) prime[j++]=i;
}
int main(){

    seive();
    long long int t;
    scanf("%lld",&t);
    while(t--){
        long long int N,i=0LL,ans=0,sq;

        scanf("%lld",&N);sq=sqrt(N);
        if(N==1){printf("1\n"); continue;}
        for(;prime[i]<sq;i++){
            if(prime[i]*(N/prime[i])==N) ans+=2LL;
        }
        ans+=(prime[i]*prime[i]==N)?1LL:0LL;
        (ans&1)? printf("YES\n"):printf("NO\n");
    }
    return 0;
}
