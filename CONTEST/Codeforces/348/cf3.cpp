#include<bits/stdc++.h>
using namespace std;

int main(){


    long long int t,b,w;
    cin >> t >> b >> w;

    long long int D=t/(b*w);
    long long int m=min(b,w);

    long long int y=D+D*(m-1)+(m-1);

    long long int gc=__gcd(y,t);
    y/=gc;
    t/=gc;
    cout<<y<<"/"<<t<<endl;

    return 0;
}
