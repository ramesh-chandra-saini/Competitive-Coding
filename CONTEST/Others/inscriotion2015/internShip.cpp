#include<bits/stdc++.h>
using namespace std;

int prime[100];
vector<int> __prime;

vector<int> factor[65];
void __init(){

    for(int i=0;i<100;i++) prime[i]=1;

    prime[0]=prime[1]=0;

    for(int i=2;i*i<100;i++){

        if(prime[i]){

            for(int j=i*i;j<100;j+=i)
                prime[j]=0;
        }
    }

    for(int i=2;i<100;i++){

        if(prime[i]) __prime.push_back(i);
    }

    for(int i=0;i<65;i++){

        factor[i].clear();
    }

    for(int i=2;i<65;i++){


        int j=0,f=0,temp=i;

        //cout<<i<<" : ";
        while(temp>1){

            f=0;
            while(temp>1 && temp%__prime[j]==0){

                f++;
                temp/=__prime[j];

            }
            if(f){
                factor[i].push_back(__prime[j]); //cout<<__prime[j]<<" ";
            }
            j++;
        }
        //cout<<endl;
    }
    return;
}

int main(){

    __init();

    int n;
    scanf("%d",&n);

    int arr[n+1];
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    int ans=1;
    int index_Holder[65];

    memset(index_Holder,0,sizeof(index_Holder));

    int size_holder[65];
    memset(size_holder,0,sizeof(size_holder));

    for(int i=0;i<65;i++) size_holder[i]=factor[i].size();

    int value=arr[1];
    int size=size_holder[value];

    for(int i=0;i<size;i++)
        index_Holder[ factor[arr[1]][i] ]=1;

    int prev_index=0;
    int div;
    for(int i=2;i<=n;i++){

        value=arr[i];
        size=size_holder[value];


        /*
        for(int i=0;i<65;i++){
            if(index_Holder[i]) cout<<i<<" ";
        }
        cout<<endl;
        */
        for(int j=0;j<size;j++){

            div=factor[value][j];
            if(index_Holder[ div ])prev_index=max(index_Holder[ div ],prev_index);
            index_Holder[div]=i;
        }
      ans=max(ans,i-prev_index);
    }
    printf("%d\n",ans);
    return 0;
}
