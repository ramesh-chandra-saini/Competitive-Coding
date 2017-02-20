#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int t; cin>>t;
    while(t--){
        ll A,B,C,D; cin >>A >> B >> C >> D;
        ll suchand=(abs(A-B)%__gcd(C,D)) ;
        if(suchand>(__gcd(C,D)-suchand)) suchand=(__gcd(C,D)-suchand);
        cout<<suchand<<endl;
    } return 0;
}
