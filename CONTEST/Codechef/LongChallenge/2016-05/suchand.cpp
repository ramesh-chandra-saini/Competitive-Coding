#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long  f[10004],i,fi,j;
long long  fun(long long  k,long long x,long long i){
	long long final_ans=0;
    if(k==0 && x==0)	return 1;
	if(k<=0||x<0) return 0;
	for(int j=i;j<fi;j++)
        if(x>=f[j]) final_ans+=fun(k-1,x-f[j],j);
        else break;
	return final_ans;
}
int main(){
    long long j,l,a,b,c,m,t,k,ans=0;
	f[0]=1;f[1]=2; i=2;
	while(1){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>1000000004) break;
		i++;
	}
	fi=i; //for(int i=0;i<fi;i++) cout<<f[i]<<" "; cout<<endl; cout<<i<<endl;
    scanf("%lld",&t);
	while(t--){
		scanf("%lld",&m);
	    scanf("%lld",&k); //cout<<m<<" "<<k<<endl;
        ans=fun(k,m,0);
        printf("%lld",ans);
        printf("\n");
  }
	return 0;
}
