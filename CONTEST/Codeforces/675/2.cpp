#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a,b,c,d,n;
ll  OK(ll A){
    if((A+a+b)-(a+c)<1LL || (A+a+b)-(b+d)<1LL || (A+a+b)-(c+d)<1LL) return -1LL;
    if((A+a+b)-(a+c)>n || (A+a+b)-(b+d)>n || (A+a+b)-(c+d)>n ) return 1LL;
    return 0LL;//return(  ( (A+a+b)-(a+d) >= 1LL && (A+a+b)-(a+d) <= n ) && ( (A+a+b)-(b+c) >= 1LL && (A+a+b)-(b+c) <= n ) && ( (A+a+b)-(c+d) >= 1LL && (A+a+b)-(c+d) <= n ) );
}
void binMax(ll s,ll e,ll &ans){
    if(s>e) return ;
    ll m=(s+e)/2LL;
    if(OK(m)==0LL) { ans=m;binMax(m+1LL,e,ans);}
    else if(OK(m)==-1LL) {binMax(m+1LL,e,ans);}
    else {binMax(s,m-1LL,ans);}
}
void binMin(ll s,ll e,ll &ans){
     if(s>e) return ;
    ll m=(s+e)/2LL;
    if(OK(m)==0LL){ans=m;binMin(s,m-1LL,ans);}
    else if(OK(m)==-1LL) { binMin(m+1LL,e,ans); }
    else {binMin(s,m-1LL,ans); };
}
int main(){
    cin >> n >> a >> b >> c >> d;
    long long int minA=INT_MAX,maxA=INT_MAX;
    binMax(1LL,n,maxA);
    binMin(1LL,n,minA);
   // cout<<minA<<" , "<<maxA<<endl;
    if(minA==INT_MAX || maxA==INT_MAX)  cout<<"0"<<endl;
    else cout<<( (maxA-minA+1LL) *n ) <<endl;
    return 0;
}
