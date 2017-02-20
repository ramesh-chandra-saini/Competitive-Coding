#include<bits/stdc++.h>
using namespace std;

int main(){


    long double i=0,r=0.00000001,__ten=10.00,p=0.25;
    cout<<(p*CLOCKS_PER_SEC)<<endl;
 vector<long double> v(100);
 int id=1;v[id]=0.0;
    for(i=0;i<1;i+=r){
        //cout<<"10^"<<i<<" : "<<pow(__ten,i)<<" "<<(int)pow(__ten,i)<<endl;
        if(id<(int)pow(__ten,i)){
            id++;
            v[(int)pow(__ten,i)]=i;
        }

    }
    for(int i=1;i<10;i++) cout<<i<<" "<<v[i]<<endl;

}
