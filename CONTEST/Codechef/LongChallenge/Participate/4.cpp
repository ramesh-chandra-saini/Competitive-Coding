/**
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define x first
#define y second

bool __cmpX(const pair<ll,ll> & a,const pair<ll,ll> & b){
        if(a.first!=b.first) return a.first<=b.first;
        return a.second<=b.second;
}
bool __cmpY(const pair<ll,ll> & a,const pair<ll,ll> & b){

    if(a.second!=b.second) return a.second<=b.second;
    return a.first<=b.first;
}
int main(){

    ll n;
    scanf("%lld",&n);
    vector<pair<ll,ll> > p(n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].y);
    ll f_ans=0;
    //sort Acc X
    sort(p.begin(),p.end(),__cmpX);
    for(int i=0;i<n;){
       ll ct=0LL,xvalue=p[i].x,yvalue=p[i].y;
        while(i<n && xvalue == p[i].x) {
            i++;
            if()ct++;
        }
        f_ans+=(ct*(ct-1))/2LL;
    }
    //sort Acc Y
    sort(p.begin(),p.end(),__cmpY);
    for(int i=0;i<n;){
        ll ct=0LL,xvalue=p[i].x,yvalue=p[i].y;
        while(i<n && yvalue==p[i].y) {i++;ct++;}
        f_ans+=(ct*(ct-1))/2LL;
    }
    //simple sort..to remove double counted
    sort(p.begin(),p.end());
    for(int i=0;i<n;){
        ll ct=0LL,xvalue=p[i].x,yvalue=p[i].y;
        while(i<n && xvalue == p[i].x && yvalue == p[i].y ) {i++;ct++;}
        f_ans-=(ct*(ct-1))/2;
    }
    printf("%lld\n",f_ans);

    //bruteforce
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll d = abs(p[i].x-p[j].x)+ abs(p[i].y-p[j].y); d*=d;
            ll m = (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
            if(d == m)ans++,cout<<"("<<p[i].x<<","<<p[i].y<<") <--> "<<"("<<p[j].x<<","<<p[j].y<<")\n";
        }
    }
    cout<<ans<<endl;

    return 0;
}

