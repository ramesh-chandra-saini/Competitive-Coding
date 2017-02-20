#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009

int C[1000006];
int D[1000006];
int  dp[1001][1001];
int pre[1001][1001];

bool prime[1001];
int size_holder[1001];
vector<int> __prime;
vector<pair<int, int> > factor[1001];
void __init(){

    memset(prime,true,sizeof(prime));

    for(int i=2;i*i<=1000;i++){

        if(prime[i]){

            for(int j=i*i;j<=1000;j+=i){

                prime[j]=false;
            }
        }
    }
    //cout<<"1"<<endl;
    __prime.clear();
    for(int i=2;i<=1000;i++){

        if(prime[i]) __prime.push_back(i);
    }
    //for(int i=0;i<__prime.size();++i) cout<<__prime[i]<<" "; cout<<endl;
    //cout<<"2"<<endl;
    for(int i=0;i<=1000;i++){

        factor[i].clear();
    }
    factor[1].push_back(make_pair(1,1));

    for(int i=2;i<=1000;i++){

        int temp=i,j=0,f=0;

        while(temp>1){

            f=0;
            while(temp>1 && temp%__prime[j]==0){

                temp/=__prime[j];
                f++;
            }

            if(f) factor[i].push_back(make_pair(__prime[j],f));
            j++;
        }
    }

     for(int i=0;i<=1000;i++)
        size_holder[i]=factor[i].size();

/*
    for(int i=0;i<=1000;i++){

        cout<<i<<" : ";
        for(int j=0;j<factor[i].size();j++){

            cout<<factor[i][j].first<<"^"<<factor[i][j].second<<" ";
        }
        cout<<" :: "<<size_holder[i]<<endl;
    }
*/
    return;
}

int LCM(int a,int b){
   return a*b/__gcd(a,b);
}


int main(){


    __init();

    int T;

    scanf("%d",&T);

    long long int N,K;

    scanf("%lld %lld",&N,&K);

    long long int A,B,M;

    scanf("%lld %lld %lld",&A,&B,&M);

    for(int i=2;i<=T;i++)
        scanf("%d",&C[i]);

   for(int i=2;i<=T;i++)
        scanf("%d",&D[i]);

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=M;i++)
        dp[i][1]=i;

     double __A,__B;
     for(int i=2;i<=M;i++){

        for(int j=2;j<=i;j++){

            __A=(double)1/double(dp[i-1][j-1]);
            __B=(double)1/double(dp[i][j-1]);
            __A=__A - __B;
            __A=double(1)/__A;
            dp[i][j]=floor(__A);
        }
     }


     memset(pre,0,sizeof(pre));

     long long int lcm=1,mult;


     int value;
     int div,times;

     int freq[1001];
     int size;
     //cout<<"FREQ"<<endl;
     for(int i=1;i<=M;i++){

        //cout<<"HI"<<endl;
        memset(freq,0,sizeof(freq));
        //for(int i=0;i<=1000;i++) cout<<freq[i]<<" "; cout<<endl;
         //cout<<"Value"<<" ";
        for(int j=1;j<=i;j++){

             lcm=1;
            if(dp[i][j]<=1000){
            value =dp[i][j];

            size=size_holder[ dp[i][j] ];
            //cout<<value<<" "<<size<<endl;
            for(int k=0;k<size;k++){

                div=factor[value][k].first;
                times=factor[value][k].second;
                freq[ div ]=max(freq[div ],times);
            }

            //cout<<"2LCM"<<endl;

            for(int k=1;k<=1000;k++){

                if(freq[k]){
                    mult=pow(k,freq[k]);
                    lcm=(lcm*mult)%MOD;
                }
            }
            }
            pre[i][j]=(int)lcm;

        }
     }

    //cout<<"ANS"<<endl;
    long long int ans;
    printf("%d\n",pre[N][K]);
    ans=pre[N][K];

    for(int t=2;t<=T;t++){

        N=1+(A*ans+C[t])%M;
        K=1+(B*ans+D[t])%N;

        printf("%d\n",pre[N][K]);
        ans=pre[N][K];
    }
    return 0;
}
