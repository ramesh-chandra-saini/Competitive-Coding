#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int t; cin>>t;
    while(t--){
        ll A,B,C,D,loop=100; cin >>A >> B >> C >> D;
        ll id=0,a=A,b=B,mn=abs(A-B);
        ll suchand=(abs(A-B)%__gcd(C,D)) ;
        if(suchand>(__gcd(C,D)-suchand)) suchand=(__gcd(C,D)-suchand);
        cout<<"Suchand : "<<suchand<<endl;

        for(int i=0;i<100000000;i++){
             if(A<B){
                    A+=max(C,C*((B-A)/C));
            } else if(A>B){
                    B+=max(D,D*((A-B)/D));
            }
            if(mn>abs(A-B)){ id=(i+1);a=A,b=B; mn=abs(A-B);}
            //cout<<(i+1)<<")."<<A<<" "<<B<<" = "<<abs(A-B)<<endl;
            if(A<0 || B<0 || A==B) break;
        }
        cout<<"Brute Force : "<<a<<" "<<b<<" = "<<abs(a-b)<<endl;
    } return 0;
}
