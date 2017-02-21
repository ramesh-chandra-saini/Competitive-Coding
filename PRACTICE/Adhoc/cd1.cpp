#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int t;
    scanf("%lld",&t);
    while(t--){
        long long int N, hash[1001];
        for(int i=0;i<=1000;i++)
            hash[i]=0L;
        scanf("%lld",&N);
        long long int arr[N];
        for(int i=0;i<N;i++){
            scanf("%lld",&arr[i]);
            hash[arr[i]]++;
        }
        long long  K;scanf("%lld",&K);
        //for(int i=0;i<=1000;i++)
            //if(hash[i]) cout<<i<<"("<<hash[i]<<")  "; cout<<endl;
        long long ans=0;
        for(int i=0;i<N;i++){
            long long int a=arr[i], b=K/arr[i];hash[a]--;
            if(a*b == K && b <= 1000)
                ans+=hash[b];//cout<<" + "<<hash[b]<<endl;
            hash[a]++;
        }
        printf("%lld\n",(ans/2));
    }
    return 0;
}
