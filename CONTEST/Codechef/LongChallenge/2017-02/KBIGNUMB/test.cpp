#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int T=1+rand()%10; printf("%d\n",T);
    while(T--){
        int A = 1+rand()%10;
        int N = 1+rand()%10;
        int M = 2+rand()%10;
        printf("%d %d %d\n",A,N,M);
    }
    return 0;
}
