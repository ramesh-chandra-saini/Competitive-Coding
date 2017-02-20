#include<bits/stdc++.h>
using namespace std;

int A[100],AL[100],AR[100];
int B[100],BL[100],BR[100];
int C[100];
int main(){

    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));

    int N;
    scanf("%d",&N);

    int ans=INT_MAX;
    int come=0,go=0;

    for(int i=1;i<N;i++)
        scanf("%d",&A[i]);

    for(int i=1;i<N;i++)
        scanf("%d",&B[i]);

    for(int i=1;i<=N;i++)
        scanf("%d",&C[i]);

   int cost1,cost2;
    for(int i=1;i<=N;i++){

            int c1=0;
            for(int k=1;k<i;k++)
               c1+=A[k];
            int c2=0;
            for(int k=i;k<N;k++)
                c2+=B[k];
            cost1=c1+C[i]+c2;
        for(int j=1;j<=N;j++){

            if(i!=j){

                int d1=0;
                for(int k=1;k<j;k++)
                    d1+=A[k];
                int d2=0;
                for(int k=j;k<N;k++)
                    d2+=B[k];
                cost2=d1+C[j]+d2;

                //cout<<cost1<<" "<<cost2<<endl;
                if(cost1+cost2<=ans) ans=cost1+cost2;
            }
        }
    }
    cout<<ans<<endl;

        return 0;
}
