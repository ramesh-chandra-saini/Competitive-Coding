#include<bits/stdc++.h>
using namespace std;

int main(){



    int T;

    scnaf("%d",&T);

    while(T--){

        int n,Q;

        scanf("%d%d",&n,&Q);

        int w[n+1];

        for(int i=1;i<=n;i++)
            scanf("%d",w[i]);
            w[i]%=26;
       bool isPresent[26];
       memset(isPresent,false,sizeof(isPresent));

        int W[n+1];
        memset(W,0,sizeof(W));

        int A,B,E=n-1;
        while(E--){

            scanf("%d%d",&A,&B);
            isPresent[w[A]]=true;
            isPresent[w[B]]=true;

            isPresent[ (w[A]+w[B])%26 ]=true;


        }

        while(Q--){


        }

    }
    return 0;
}
