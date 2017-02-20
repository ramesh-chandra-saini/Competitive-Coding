#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[2][2] = {{1LL,0LL},{0LL,1LL}};
ll A[2][2]= {{-2LL,-9LL},{1LL,4LL}};

void mult(){
    ll c[2][2] ={{0LL,0LL},{0LL,0LL}};
    for(ll i=0;i<2;i++)
        for(ll j=0;j<2;j++)
            for(ll k=0;k<2;k++)
                c[i][j]+=a[i][k]*A[k][j];
    for(ll i=0;i<2;i++)
        for(ll j=0;j<2;j++)
            a[i][j] = c[i][j];
}
int main(){

    for(ll i=1;i<=1000;i++){
        mult();
    }
    cout<<a[0][0]<<endl;
    cout<<a[0][1]<<endl;
    cout<<a[1][0]<<endl;
    cout<<a[1][1]<<endl;
        return 0;
}
