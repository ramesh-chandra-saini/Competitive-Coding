#include<bits/stdc++.h>
using namespace std;

bool isPrime[10001];
int fact[1229];
int      arr[10001];
void init(){

    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i<=100;i++)
        if(isPrime[i]==true)
            for(int j=i*i;j<=10000;j+=i)
                isPrime[j]=false;

    for(int i=0,j=0;i<=10000;i++)
        if(isPrime[i]) fact[j++]=i;
}

int main(){

    init();

    int T,N;
    scanf("%d",&T);

    while(T--){

        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&arr[i]);

        int sum=0;

        /* check if arr[0]==1 change it to 2*/
        if(arr[0]==1)
            arr[0]=2,sum=1;

        int gcd=arr[0];

        for(int i=1;i<N;i++){

            if(arr[i]<arr[i-1])
                sum+=(arr[i-1]-arr[i]) , arr[i]=arr[i-1];
            gcd=__gcd(gcd,arr[i]);
        }
        if(gcd==1) {

            int add_more=INT_MAX;
            for(int i=0;i<1229;i++){

                    int checker=0;
                    for(int j=0;j<N;j++)
                        checker+=(arr[j]%fact[i]==0) ? 0 : (  fact[i]- ( arr[j] % fact[i] )   );
                    add_more=min(add_more,checker);
            }
            sum+=add_more;
        }
        printf("%d\n",sum);
    }
    return 0;
}
