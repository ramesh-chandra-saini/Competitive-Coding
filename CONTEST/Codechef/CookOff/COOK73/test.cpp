#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    long long t,n; t=1+rand()%10; cout<<t<<endl; while(t--){
        n = 2+(rand()%4); cout<<n<<endl;
        for(long long i=0,value;i<n;i++) value=rand()%1000000000,printf("%lld ",value); cout<<endl;
    } return 0;
}
