#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D 1000000000000000000
ll get(ll A,ll a=0){
    a = sqrt(A) ;
    if(a*a<=A)
    	while(a+1<=A&&(a+1)*(a+1)<=A) ++a;
   	else
   		while(a-1>=0 && (a-1)*(a-1)>=A)	--a;
    return a;
}
ll bf(ll A,ll a=0){
    while(a+1<=A&&(a+1)*(a+1)<=A) ++a;
    return a;
}
int main(){
    ll t; cin >> t;while(t--){
        ll d = rand()%D;
        ll g = get(d);
        ll b = bf(d);
        if(g==b && g*g<=d && b*b<=d){
            cout<<g*g<<" == "<<b*b<<" "<<d<<endl;
        }else{
            cout<<g*g<<" != "<<b*b<<" "<<d<<endl;
            break;
        }
    } return 0;
}
