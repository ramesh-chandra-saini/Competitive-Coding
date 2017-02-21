#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n; t=1+rand()%10; while(t--){
        n = 2+(rand()%100000);
        for(long long i=0,value;i<n;i++) value=rand()%1000000000,printf("%lld ",value); cout<<endl;
    } return 0;
}
