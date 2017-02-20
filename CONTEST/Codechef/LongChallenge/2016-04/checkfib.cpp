#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    long long int a=0,b=1,c=1,ct=2;/*
    long long int L = (1LL<<62)+(1LL<<61)+(1LL<<60);
    while( a>=0 && a<L && b>=0 && b<L&& a+b<L && a+b>0){ ct++;
        c=a+b; cout<<c<<endl;
        a=b;b=c;
    }
    cout<<"\n*********\n"<<ct<<"\n*********\n"; cout<<L<<endl;*/
    set<int> s;s.clear();
    a=0;b=1;c=1; s.insert(a);s.insert(b);
    for(int i=2;i<=10000000;i++){
        c=(a+b)%MOD;a=b;b=c; //cout<<c<<" ";
        s.insert(c);
    }
    for(set<int> :: iterator it = s.begin();it!=s.end();++it)
        cout<<(*it)<<" "; cout<<endl;
    cout<<s.size()<<endl;
}
