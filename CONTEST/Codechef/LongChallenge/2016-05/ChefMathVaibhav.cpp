/*
    problem structure perposed by Vaibhav
    fill k boxes using fibonacci number such that sum of all terms will be X(given number)
    Thanks to Vaibhav..21 topo ki salami...what a transformation...from one problem to other one
*/
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define M 1000000000
vector<ll> fib(43);
void Fibo(){//fibonacci series generator..
    ll a=1,b=2,i=0,c;fib[i++]=(a),fib[i++]=(b);
    while(a+b<=M)//generate all possible fibonacci numbers
        c=a+b,fib[i++]=c,a=b,b=c;
}
ll solve(ll X,ll K,ll lastInsertedTerm){//solve recursion
    if(X==0 && K==0) return 1;//valid combination
    if(K>0 && X>0);//valid combination for further
    else return 0;//invalid combination
    ll ans=0;
    for(ll i=0;i<fib.size() && fib[i]<=X;i++){
        if(fib[i]<=lastInsertedTerm){
            if((X-(K*fib[i]))<=0){ //if you can not make zero using this value..no one can do..so through them
                ans+=solve(X-fib[i],K-1,fib[i]);//ans%=MOD;
            }
        }
    }
    return ans;//return combination from here
}
int main(){
    Fibo();//generate fibonacci numbers
    ll t; scanf("%d",&t);
    while(t--){
        ll X,K; scanf("%d%d",&X,&K);
        printf("%d\n",solve(X,K,fib[fib.size()-1]));
    }
    return 0;
}
