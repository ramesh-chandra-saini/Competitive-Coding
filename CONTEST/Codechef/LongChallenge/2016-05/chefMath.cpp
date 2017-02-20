#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> fib;
ll n=1;
void Fibo(ll M){
	fib.push_back(1); fib.push_back(2);
	ll a=1,b=2,c=3;
	while(a+b<=M){
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

    ll Q; scanf("%lld",&Q);
    while(Q--){
        ll ans=0;
        ll X,K; scanf("%lld%lld",&X,&K); fib.clear();
        Fibo(X);
        ll temp=X;
        ll idx=0;
        bin(fib,0,n-1,temp,idx);
        for(ll i=0;i<idx+1 && K>=1;i++){
            ll temp1=temp-fib[i];
            if(K==1 && temp1==0){
                ans=ans+1; break;
            }
            ll idx1=0;bin(fib,i,n-1,temp1,idx1);
            for(ll j=i;j<idx1+1 && K>=2;j++){
                ll temp2=temp1-fib[j];
                if(K==2 && temp2==0){
                 ans=ans+1;break;
                 }
                ll idx2=0;bin(fib,j,n-1,temp2,idx2);
                for(ll k=j;k<idx2 +1 && K>=3;k++){
                    ll temp3=temp2-fib[k];
                    if(K==3 && temp3==0){
                    ans=ans+1;break;
                    }
                    ll idx3=0;bin(fib,k,n-1,temp3,idx3);
                    for(ll l=k;l<idx3 +1 && K>=4;l++){
                        ll temp4=temp3-fib[l];
                        if(K==4 && temp4==0){
                        ans=ans+1;break;
                        }
                        ll idx4=0;bin(fib,l,n-1,temp4,idx4);
                        for(ll m=l;m<idx4 +1 && K>=5;m++){
                            ll temp5=temp4-fib[m];
                            if(K==5 && temp5==0){
                                ans=ans+1;break;
                            }
                            ll idx5=0;bin(fib,m,n-1,temp5,idx5);
                            for(ll o=m;o<idx5 +1 && K>=6;o++){
                                ll temp6=temp5-fib[o];
                                if(K==6 && temp6==0){
                                    ans=ans+1;break;
                                }
                                ll idx6=0;bin(fib,o,n-1,temp6,idx6);
                                for(ll p=o;p<idx6 +1 && K>=7;p++){
                                    ll temp7=temp6-fib[p];
                                    if(K==7 && temp7==0){
                                        ans=ans+1;break;
                                    }
                                    ll idx7=0;bin(fib,p,n-1,temp7,idx7);
                                    for(ll q=p;q<idx7 +1 && K>=8;q++){
                                        ll temp8=temp7-fib[q];
                                        if(K==8 && temp8==0){
                                            ans=ans+1;break;
                                        }
                                        ll idx8=0;bin(fib,q,n-1,temp8,idx8);
                                        for(ll r=q;r<idx8 +1 && K>=9;r++){
                                            ll temp9=temp8-fib[r];
                                            if(K==9 && temp9==0){
                                                ans=ans+1;break;
                                            }
                                            ll idx9=0;bin(fib,r,n-1,temp9,idx9);
                                            for(ll s=r;s<idx9 +1 && K>=10;s++){
                                                ll temp10=temp9-fib[s];
                                                if(K==10 && temp10==0){
                                                    ans=ans+1;break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
