#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int N = 1+rand()%1000;
    int L = 1+rand()%10000;
    int R = 1+rand()%10000;
    printf("%d %d %d\n",N,min(L,R),max(L,R));
    for(int i=0;i<N;i++)
        cout<<(1+rand()%100)<<" ";
    cout<<endl;
    return 0;
}
