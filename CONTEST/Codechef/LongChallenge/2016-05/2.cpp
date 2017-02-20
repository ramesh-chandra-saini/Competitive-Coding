#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> fib;
#define M 1000000000
void Fibo(){
    fib.clear();
    ll a=1,b=2,c; fib.push_back(a); fib.push_back(b);
    while(a+b<=M)
        c=a+b, fib.push_back(c),a=b,b=c;
    //for(ll i=0;i<fib.size();i++) cout<<fib[i]<<" "; cout<<"\t("<<fib.size()<<")"<<endl;
}
bool binarySearch(vector<ll> &fib,ll s,ll e,ll key){
    if(s>e) return false;
    ll m=(s+e)/2;
    if(fib[m]==key) return true;
    else if(fib[m]<key) return binarySearch(fib,m+1,e,key);
    else return binarySearch(fib,s,m-1,key);
}
vector<pair<ll,ll> > dp;
vector<pair<ll,ll> > sepratedp;
vector<pair<ll,ll> > finaldp;
void makeList(){
    dp.push_back(make_pair(1,1));
    dp.push_back(make_pair(2,1));
    ll curr=2,target=3,loop=100;

    for(ll i=0;;){
        ll newTerm=curr+dp[i].first;
        ll freq=1+dp[i].second;
        if(newTerm==target){
            dp.push_back(make_pair(newTerm,1));
            ll a=curr,b=target; curr=target; target=a+b;i=0;
        }else if(freq==10){
            sepratedp.push_back(make_pair(newTerm,freq));i++;
        }else if(freq<=9){
            dp.push_back(make_pair(newTerm,freq));i++;
        } else{//through it away..no use
            i++;
        }
        if(curr>M) break;//terminating condition
    } ll s=dp.size();
    //finaldp.reserve(dp.size()+sepratedp.size());
    //finaldp.insert(finaldp.end(),dp.begin(),dp.end());
    //finaldp.insert(finaldp.end(),sepratedp.begin(),sepratedp.end());
    //sort(finaldp.begin(),finaldp.end());
    //for(ll i=0;i<finaldp.size();i++) cout<<finaldp[i].first<<"("<<finaldp[i].second<<")"<<endl;
    cout<<s<<"  "<<s/(double)M<<endl;
}
int main(){
    Fibo();;
    makeList();
    return 0;
}
