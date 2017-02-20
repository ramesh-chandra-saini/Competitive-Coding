#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000000
#define pb push_back
#define mp make_pair
vector<ll> ___fib;
void Fibo(){
    ll a=1,b=2,c;
    ___fib.pb(a);___fib.pb(b);
    while(a+b<=MAX)
        c=a+b,___fib.pb(c),a=b,b=c;
    //for(ll i=0;i<___fib.size();i++)cout<<___fib[i]<<"  "; cout<<"\t("<<___fib.size()<<")"<<endl;
}
bool bin(vector<ll> &___fib,ll s,ll e,ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(___fib[m]==key) return true;
    else if(___fib[m]<key) return bin(___fib,m+1,e,key);
    else return bin(___fib,s,m-1,key);
}
void findNextNearest(vector<ll> &___fib,ll s, ll e,ll key,ll &ans){
    if(s>e) return;
    ll m=(s+e)/2LL;
    if(___fib[m]>key){
        ans=min(ans,___fib[m]);
        return findNextNearest(___fib,s,m-1,key,ans);
    }else return findNextNearest(___fib,m+1,e,key,ans);
}
bool binSearch(vector<ll> & Present,ll s,ll e, ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(Present[m]==key) return true;
    if(Present[m]<key) return binSearch(Present,m+1LL,e,key);
    return binSearch(Present,s,m-1LL,key);
}
vector<pair<ll,ll> > __list(100000000);
ll listSize=0;
void Checker(){

    clock_t startTime=clock();
    Fibo();
    ll a=1LL,b=2LL,c;
    __list.clear();
    vector<ll> Present; Present.clear();Present.pb(a); Present.pb(b);
    __list[listSize++]=(mp(a,1));__list[listSize++]=(mp(b,1));
    //cout<<"Base Terms :\n1)."<<a<<"("<<"1"<<")   \n2). "<<b<<"("<<"1"<<")"<<endl;
    ll i=0,j=1;
    ll Terminator=1000000005,terms=3,newTerm=2,freq=1;
    for(;i<j && Terminator-- && __list.size()<100000000;){
        newTerm=__list[i].first+__list[j].first;
        freq=__list[i].second+__list[j].second;
        if(bin(___fib,0,___fib.size()-1,newTerm)==true){
            __list[listSize](mp(newTerm,1));
            //cout<<terms++<<"). "<<__list[i].first<<"("<<__list[i].second<<")  + "<<__list[j].first<<"("<<__list[j].second<<")"<<" = "<<newTerm<<"("<<"1"<<")";
            i=0;
            j=__list.size()-1;
            //printf("  ___fib[%lld] : %lld , ___fib[%lld] : %lld \n",i,__list[i].first,j,__list[j].first);
            //cout<<newTerm<<" ";
            Present.pb(newTerm);
        }else {
            __list.pb(mp(newTerm,freq));
            //cout<<terms++<<"). "<<__list[i].first<<"("<<__list[i].second<<")  + "<<__list[j].first<<"("<<__list[j].second<<")"<<" = "<<newTerm<<"("<<freq<<")"<<endl;
            i++;
            //cout<<newTerm<<" ";
            Present.pb(newTerm);
        }
    }
    for(ll i=0;i<__list.size();i++) cout<<__list[i].first<<"("<<__list[i].second<<") "; cout<<endl;
    //cout<<"\nLast Accessed Term : "<<newTerm<<" \nListSize : "<<__list.size()<<endl;
    //cout<<double(__list.size()/newTerm)<<endl;
    //clock_t endTime=clock();
    //double duration = (float)(endTime-startTime)/CLOCKS_PER_SEC;
    //cout<<duration<<endl;
    cout<<Present.size()<<endl;
 //   return binSearch(Present,0,Present.size()-1,item);
}
int main(){
    Checker();
    return 0;
}

