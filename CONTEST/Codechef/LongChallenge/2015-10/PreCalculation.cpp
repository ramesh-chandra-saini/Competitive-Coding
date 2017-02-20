#include<bits/stdc++.h>
using namespace std;

int main(){

    int i,n,C=50000;
    double t=clock();
    t=clock()-t;
   long long int k,_k;
    for(int j=0;j<=C;j++){

        bool flag=false;
        n=j;
        for(i=1;i<n;i++){
            k=n*n-i*i;
            _k=sqrt(k);

            if(_k*_k==k){
                cout<<"1 ";
                cout<<
                break;
            }
        }
        if(i==n)cout<<"0 ";
    }
    cout<<endl;
    t=clock()-t;
    cout<<clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
