#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> fib;
#define M 1000000001
ll n=1;
void Fibo(){
	fib.push_back(1); fib.push_back(2);
	ll a=1,b=2,c=3;
	while(a+b<M){
        c=a+b; fib.push_back(c); a=b;b=c;
	}
	n=fib.size();
}
void bin(vector<ll> &fib, ll s,ll e,ll temp, ll &idx){
	if(s>e) return ;
	ll m=(s+e)/2;
	if(fib[m]<=temp){
		idx=max(idx,m);
		bin(fib,m+1,e,temp,idx);
	} else bin(fib,s,m-1,temp,idx);
}
int main(){
    Fibo();
    ll Q; cin>>Q;
    while(Q--){
        ll ans=0;
        ll X,K; cin >>X >> K;
        ll temp=X;ll idx=0;bin(fib,0,n-1,temp,idx);
    for(ll i=0;i<idx+1;i++){
        temp=temp-fib[i];
        if(K==1 && temp==0)
            ans=ans+1;
        idx=0;bin(fib,i,n-1,temp,idx);
        for(ll j=i;j<idx+1;j++){
            temp=temp-fib[j];
            if(K==2 && temp==0)
            ans=ans+1;
            idx=0;bin(fib,j,n-1,temp,idx);
            for(ll k=j;k<idx+1;k++){
                temp=temp-fib[k];
                if(K==3 && temp==0)
                    ans=ans+1;
                idx=0;bin(fib,k,n-1,temp,idx);
                for(ll l=k;l<idx+1;l++){
                    temp=temp-fib[l];
                    if(K==4 && temp==0)
                        ans=ans+1;
                    idx=0;bin(fib,l,n-1,temp,idx);
                    if(K==5);
                    for(ll m=k;m<idx+1;m++){
                        temp=temp-fib[m];
                        if(K==5 && temp==0)
                            ans=ans+1;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
