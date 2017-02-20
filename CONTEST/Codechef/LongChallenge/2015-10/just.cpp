#include<bits/stdc++.h>
using namespace std;

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

    for(int i=0;i<=1000;i++){

        printf("%d). ",i);
        for(int j=0;j<factor[i].size();++j){

            printf("%d^%d ",factor[i][j].value,factor[i][j].freq);
        }
        printf("\n");
    }
    return ;
}
int main(){

    __init();
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin >> arr[i];

   int fact_freq[1001];
   memset(fact_freq,0,sizeof(fact_freq));

    long long int lcm=1;
    long long int m=1000000007;

    for(int i=0;i<n;i++){

        int idx=arr[i];
        int sz=factor[idx].size();
        for(int j=0;j<sz;j++){

            printf("%d^%d ",factor[idx][j].value,factor[idx][j].freq);
            int fact=factor[idx][j].value;
            fact_freq[ fact ]=max(fact_freq[ fact ], factor[idx][j].freq  );
        }
       lcm=1;
       for(int j=1;j<=1000;j++){

            if(fact_freq[j]){

                lcm=lcm*pow(j,fact_freq[j]);
                lcm%=m;
            }
       }
       printf("%lld\n",lcm);
    }
    return 0;
}
