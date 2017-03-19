#include<bits/stdc++.h>
using namespace std;
#define MaxN 1000
#define MaxA 1000000000
#define MaxQ 1000
int main(){
    srand(time(NULL));
    int N;
    N=1+rand()%MaxN;
    printf("%d\n",N);
    for(int i=0;i<N;i++)
        printf("%d ",rand()%MaxA);
    printf("\n");
    int Q;
    Q=1+rand()%MaxQ;
    printf("%d\n",Q);
    for(int i=0;i<Q;i++){
        int L;
        L=1+rand()%N;
        int R;
        R=1+rand()%N;
        if(L>R)
            swap(L,R);
        printf("%d %d\n",L,R);
    }
}
