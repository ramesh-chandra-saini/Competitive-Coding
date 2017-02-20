#include<iostream>
#include<bits/stdc++.h>

using namespace std;
long long  MOD=1000000009;
 long long fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1LL;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
long long findMMI_fermat(long long n,long long M)
{
    return fast_pow(n,M-2,M);
}
long long storeFactor[100006];
long long  factorial(long long N)
{
    long long ans = 1LL;
    storeFactor[0]=1LL;
    long long i;
    for(i=1; i <= N; i++){
        ans = (ans*i)%MOD;
        storeFactor[i]=ans%MOD;
    }
    return ans;
}
//#define ll long long int
//ll fact[10005];
int main(){
    //fact[0]=1LL;for(ll i=1LL;i<100005;i++)fact[i]=(fact[i-1]*i)%MOD;
	long long  n,k,a[100005],i,j,sum,t,count1,ans,inter,q;
	scanf("%lld",&t); bool flag=true;
	//ll Testans,T=t;
	while(t--){
	sum=0,count1=0;
	//n =rand()%100000+1;//
	scanf("%lld",&n);
	//k =rand()%100000+1;//
	scanf("%lld",&k);
	for(i=0;i<n;i++){
		//a[i]=rand()%(200001)-100000;//
		scanf("%lld",&a[i]);
	}//cout<<n<<" "<<k<<endl;for(i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
    for(i=0;i<n;i++){
     	if(a[i]==0){
     		count1++;
		 }
	 }
    //if(n==1) Testans=1;else Testans=Solve(n-count1,k,count1);

	 if(count1){
	 n=n-(count1-1);
    }
	 if(k>n){
		k-=(k-n)+(k-n)%2;
	}
    factorial(n);
	for(i=k;k>=0;k=k-2){
		ans=storeFactor[n];
		q=(storeFactor[k]*storeFactor[n-k])%MOD;
		 inter=findMMI_fermat(q,MOD);
		 ans=((ans%MOD)*(inter%MOD))%MOD;
		sum=(sum+ans)%MOD;
	}
    //cout<<"Tester Sol : "<<Testans<<endl;
	printf("%lld\n",sum);
    //flag=flag&(Testans==sum);
}
//if(flag) cout<<"verdict : AC  TestCases : "<<T<<endl;else cout<<"verdict : WA TestCase : "<<T<<endl;
	return 0;
}
