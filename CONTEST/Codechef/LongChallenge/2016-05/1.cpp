#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> fib;
#define MAX 1000000000
vector<vector<ll> > List(11);
void Fibo(){

    ll a=1LL,b=2LL,c; fib.clear(); fib.push_back(a); fib.push_back(b);
    while(a+b<=MAX)
        c=a+b,fib.push_back(c),a=b,b=c;
   // for(ll i=0;i<fib.size();i++) cout<<fib[i]<<" "; cout<<"  SIZE : ("<<fib.size()<<")"<<endl;
}
bool binFib(vector<ll>&fib,ll s,ll e,ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(fib[m]==key) return true;
    else if(fib[m]>key) return binFib(fib,s,m-1LL,key);
    else return binFib(fib,m+1LL,e,key);
}
void PrepareList(){
    for(ll i=0;i<=10;i++) List[i].clear();
    ll a=1LL,b=2LL,c;
    List[1].push_back(a);
    List[1].push_back(b);

    vector<pair<ll,ll> > p; p.clear();
    for(ll i=0;i<=10;i++){
        for(ll k=0;k<List[i].size();k++){
            p.push_back(make_pair(List[i][k],i));
        }
    }
    sort(p.begin(),p.end());
    for(ll i=0;i<p.size();i++) cout<<p[i].first<<"("<<p[i].second<<")"<<endl; cout<<endl;
}
int main(){
    Fibo();
    PrepareList();

}
