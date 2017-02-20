#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int T=1+rand()%10; printf("%d\n",T);
    while(T--){
        int N = 1+rand()%10; printf("%d\n",N);
        for(int i=1;i<=N;i++)
            printf("%d ",rand()%2); printf("\n");
    }
    return 0;
}
