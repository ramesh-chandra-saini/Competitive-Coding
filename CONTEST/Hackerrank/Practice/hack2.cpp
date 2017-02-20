#include<bits/stdc++.h>
using namespace std;

bool prime[8001];

vector<int> __prime;
int Query[8001];

//1 Yes -1 No 0 Do n;t know
void __init(){


    for(int i=0;i<=8000;i++)
        prime[i]=true;

    prime[0]=prime[1]=false;

    for(int i=0;i*i<=8000;i++){

        if(prime[i]){

            for(int j=i*i;j<=8000;j+=i)
                prime[j]=false;
        }
    }

    memset(Query,0,sizeof(Query));

    for(int i=0;i<=8000;i++)
        if(prime[i]) {Query[i]=1; __prime.push_back(i); }

    for(int idx=2;idx<8000;idx=idx*2){

        int j=idx+1;
        while(j<=8000 && Query[j]==0){

            Query[j]=-1;
            j++;
        }
    }

    for(int i=0;i<=8000;i++)
        if(i%2==0) Query[i]=-1;
   int ct=0;

    for(int i=0;i<=200;i++)
        if(Query[i]==0) ct++;

    //cout<<ct<<endl;


    for(int i=0;i<=200;i++){

        if(Query[i]==0){


            int A=2,B=0,C=0,D=0;
            bool flag=true;
            for(int j=0;__prime[j]<=i && flag;j++){
                    A=__prime[j];
                    if((A|B|C|D )==i) flag=false;
                for(int k=0;k<j && flag;k++){
                    B=__prime[k];
                    if((A|B|C|D )==i) flag=false;
                    for(int l=0;l<k && flag;l++){
                        C=__prime[l];
                        if((A|B|C|D )==i) flag=false;
                        for(int m=0;m<l && flag;m++){
                            D=__prime[m];
                            if((A|B|C|D )==i) flag=false;
                        }
                    }
                }
            }
         if(flag) Query[i]=-1;
         else Query[i]=1;
        }
    }
    //cout<<ct<<endl;
}
int main(){

    __init();

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        if(Query[n]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
