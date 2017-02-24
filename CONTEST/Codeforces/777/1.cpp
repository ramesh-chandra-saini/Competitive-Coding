#include<bits/stdc++.h>
using namespace std;

long  fun(vector<long> shell,long N){
    for(long j=1;j<=N;j++){
        if(j%2==1)
            swap(shell[0],shell[1]);
        else
            swap(shell[1],shell[2]);
    }
    for(long i=0;i<=2;i++)
        if(shell[i]==1)
            return i;
    return 0LL;
}
int main(){
    long N; cin >> N; N%=(5*4*6);
    long I; cin >> I;
    for(long i=0;i<3;i++){
        vector<long> shell(3,0);
        shell[i]=1;
        if(fun(shell,N)==I)
            cout<<i<<endl;
    }
    cout<<"\n";
    return 0;
}
