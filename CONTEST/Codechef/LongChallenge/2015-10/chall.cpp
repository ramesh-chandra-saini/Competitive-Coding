#include<bits/stdc++.h>
using namespace std;

int OP[1000000][2];
int main(){

    int N,M;
    ///cin>>N>>M;
      scanf("%d %d",&N,&M);

    int T=CLOCKS_PER_SEC*(float) 4.95;
    int X[M],Y[M],Z[M];

    for(int i=0;i<M;i++,T--)
        ///cin>>X[i]>>Y[i]>>Z[i];
        scanf("%d %d %d",&X[i],&Y[i],&Z[i]);
    int K;
    ///cin >>K;
    scanf("%d",&K);

    int A[K],B[K],V[K],C[K];

    for(int i=0;i<K;i++,T--)
        ///cin>>A[i]>>B[i]>>V[i]>>C[i];
        scanf("%d %d %d %d",&A[i],&B[i],&V[i],&C[i]);

    int S,D,W;

    ///cin>>S>>D>>W;
    scanf("%d %d %d",&S,&D,&W);


    int op=0;

    int size=min(385,K);

    for(int i=0;i<size && T--;i++){

        bool flag=true;
        for(int j=0;j<M && T-- && op<900000 && flag;j++){

            ///Direct Way from Source to Delivery Destination
            if(   ( S==X[j] && X[j]==A[i] && Y[j]==B[i] )   ||
                     (S==Y[j] &&  Y[j]==A[i] && X[j]==B[i] )   ){

                    if(D>=Z[j] && W>=V[i]){

                        OP[op][0]=1; OP[op++][1]=A[i];
                        OP[op][0]=2; OP[op++][1]=B[i];
                        D-=Z[j]; //W-=V[i];
                        ///Deliver packet;
                        ///Now I am at first order destination...try to get some order
                        S=B[i];
                        flag=false;
                        break;
                    }
            }
        }
     }

   ///cout<<op<<endl;
    printf("%d\n",op);

    if(op){

           for(int i=0;i<op;i++){
                ///cout<<OP[i][0]<<" "<<OP[i][1]<<endl;
                printf("%d %d\n",OP[i][0],OP[i][1]);
            }
    }
    return 0;
}
