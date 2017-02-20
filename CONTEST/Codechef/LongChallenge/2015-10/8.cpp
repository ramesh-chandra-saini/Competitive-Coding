#include<bits/stdc++.h>
using namespace std;

int  dp[1001][1001];
int pre[1001][1001];
long long int c[1001];
long long int d[1001];

#define value first
#define  freq second
         // value,freq
vector< vector<pair<int,int> > >factor(1001);
vector<bool> __prime(1001,true);
vector<int> prime;

void __init(){

    __prime[0]=__prime[1]=false;

    for(int i=2;i*i<=1000;i++){

        if(__prime[i]){

            for(int j=i*i;j<=1000;j+=i){

                __prime[j]=false;
            }
        }
    }
    prime.clear();
    for(int i=0;i<=1000;i++){

        if(__prime[i]) prime.push_back(i);
    }

    for(int i=0;i<=1000;i++){

        factor[i].clear();
    }
    factor[0].push_back(make_pair(0,1));
    factor[1].push_back(make_pair(1,1));
    for(int i=2;i<=1000;i++){

        int temp=i,j=0,f=0;

        while(temp>1){

            f=0;
            while(temp>1 && temp%prime[j]==0){
                temp/=prime[j]; f++;
            }
           if(f) factor[i].push_back(make_pair(prime[j],f));
           j++;
        }
    }
    return ;
}
long long int power(int n,int exp){

    long long int N=n,ans=1;
    long long int mod=1000000007;

    if(N==1) return N%mod;
    if(!exp) return 1;

    while(exp){

        if(exp%2){

            ans=(ans*N)%mod;
        }

        N=(N*N)%mod;
        exp/=2;
    }
    return ans;
}
int main(){

    __init();

    int t;
    scanf("%d",&t);

    long long int n,k;
    scanf("%lld %lld",&n,&k);

    long long int a,b,m;
    scanf("%lld %lld %lld",&a,&b,&m);

    memset(c,0,sizeof(c));
    for(int i=2;i<=t;i++){

        scanf("%lld",&c[i]);
    }

    memset(d,0,sizeof(d));
    for(int i=2;i<=t;i++){

        scanf("%lld",&d[i]);
    }

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++) {

        dp[i][1]=i;
    }

    //cout<<endl;
    for(int i=2;i<=m;i++){

        for(int j=2;j<=i;j++){

           if((dp[i][j-1]-dp[i-1][j-1])){
                dp[i][j]=(dp[i-1][j-1]*dp[i][j-1])/(dp[i][j-1]-dp[i-1][j-1]);
                //cout<<dp[i][j]<<"   ";
           }
           else {

                dp[i][j]=0;
                //0000cout<<"'0' ";
            }
        }
        //cout<<endl;
    }
    //cout<<endl;



    memset(pre,0,sizeof(pre));
    int fact_freq[1001];
    long long int lcm=1,P;
    long long int mod=1000000007;

    for(int i=1;i<=m;i++){


        memset(fact_freq,0,sizeof(fact_freq));
        for(int j=1;j<=i;j++){

            int idx=dp[i][j];

            int sz=factor[idx].size();

            for(int _j=0;_j<sz;_j++){

                //printf("%d^%d ",factor[idx][_j].value,factor[idx][_j].freq);
                int fact=factor[idx][_j].value;
                fact_freq[ fact ]=max(fact_freq[ fact ], factor[idx][_j].freq  );
            }
            lcm=1;

            for(int _j=1;_j<=1000;_j++){

                if(fact_freq[_j]){

                    P=power(_j,fact_freq[_j]);
                    lcm=(lcm*P)%mod;
                }
            }
            pre[i][j]=(int)lcm;
        }
    }

    int ans=0;
    printf("%d\n",ans=pre[n][k]);

    for(int i=2;i<=t;i++){

        n=1+(a*ans+c[i])%m;
        k=1+(b*ans+d[i])%n;
        printf("%d\n",ans=pre[n][k]);
    }
    return 0;
}
