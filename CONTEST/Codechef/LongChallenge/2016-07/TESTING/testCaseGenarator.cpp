#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; t= rand()%5+1; cout<<t<<endl;
    while(t--){
        int n = rand()%1000+1; cout<<n<<endl;
        while(n--) cout<<( rand()%1000000000+1 )<<" "; cout<<endl;
    }  return 0;
}
