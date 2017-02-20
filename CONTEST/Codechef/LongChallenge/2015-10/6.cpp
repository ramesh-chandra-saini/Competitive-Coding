#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;

    scanf("%d",&t);

    while(t--){


        int N,K,i,j;
        scanf("%d%d",&N,&K);

        int P[N];
        for(i=0;i<N;i++)
            scanf("%d",&P[i]);
        int Q[N];
        for(i=0;i<N;i++)
            scanf("%d",&Q[i]);

        int key=P[0],idx=0;

        for(int i=0;i<N;i++){

            if(Q[i]==key) idx=i;
        }

        bool flag=true;


        for(i=0,j=idx;j<N;i++,j++){

            if(P[i]!=Q[j]) flag=false;
        }

        for(j=0;j<idx ; i++,j++){

            if(P[i]!=Q[j]) flag=false;
        }

        if(!flag) printf("-1\n");
        else{

            printf("%d\n",Q[0]);
        }
    }
    return 0;
}
