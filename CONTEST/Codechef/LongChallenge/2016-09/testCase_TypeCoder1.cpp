#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int t; t=1+rand()%10; cout<<t<<endl;
    while(t--){
        int n= 1+rand()%2000; cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<(1+rand()%1000000000)<<" ";
        } cout<<endl;
    }
    return 0;
}
