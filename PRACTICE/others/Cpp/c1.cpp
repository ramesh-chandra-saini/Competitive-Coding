#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int j,s,m;

    cin >> j >> s >> m;
        m-=j;
    s=m/s;
    if(s&1) cout<<"Unlucky Chef"<<endl;
    else cout<<"Lucky Chef"<<endl;
    return 0;
}
