#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int T; T = 1+rand()%100;
    printf("%d\n",T);
    while(T--){
        int N=5,P=3; N = 1+rand()%10;P=1+rand()%20;
        printf("%d %d\n",N,P);
        for(int i=0;i<N;i++)
            printf("%d ",rand()%10);
        printf("\n");
        for(int i=0;i<N;i++)
            printf("%d ",rand()%10);
        printf("\n");
    }
    return 0;
}
