#include<bits/stdc++.h>
using namespace std;

bool __prime[5000006];
bool      dp[5000006];
void __init(){


    memset(__prime,true,sizeof(__prime));

    __prime[0]=__prime[1]=false;
    for(int i=2;i*i<5000006;i++){

        if(__prime[i]){

            for(int j=i*i;j<5000006;j+=i){

                __prime[j]=false;
            }
        }
    }

    memset(dp,false,sizeof(dp));

    for(int k=1,i=4*k+1;i<5000006;i=4*(++k)+1){

        if(__prime[i]){
            for(int j=i;j<5000006;j+=i){

                dp[j]=true;
            }
        }
    }
    return;
}
int main(){

    __init();

    int t;

    scanf("%d",&t);

    while(t--){

        int n;

        scanf("%d",&n);

        if(dp[n]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
