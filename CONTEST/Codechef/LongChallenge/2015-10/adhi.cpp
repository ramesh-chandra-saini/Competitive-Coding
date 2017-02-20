#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;

    scanf("%d",&t);

    while(t--){

        int V,Q;

        scanf("%d %d",&V,&Q);

        int got=26;


        int w[V+1];
        bool isPresent[26];
        memset(isPresent,false,sizeof(isPresent));

        for(int i=1;i<=V;i++){

            scanf("%d",w[i]);
            w[i]%=26;

            if(isPresent[ w[i]  ]){

                got--;
            }
            isPresent[ w[i] ]=true;
        }

        int root[ V+1 ];
        memset(root,0,sizeof(root));
        int N=V-1;

        int A,B;
        while(N--){

            scanf("%d %d",&A,&B);


            root[B]=A;
            if(!root[A])
                root[A]=A;
        }

       for(int )

        while(Q--){

        }

    }
    return 0;
}
