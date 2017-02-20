#include<bits/stdc++.h>
using namespace std;

int main(){

    int k=0;
    for(int i=0;i<999;i++){
        if(i%8==0)
            k++,cout<< i<<" ";
    }
    cout<<endl<<k<<endl;
    return 0;
}
