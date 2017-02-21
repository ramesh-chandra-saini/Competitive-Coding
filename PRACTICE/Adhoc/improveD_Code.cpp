#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int t,n,k,i,j;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		long long int arr1[n],arr2[n],sum=0;
		for(i=0;i<n;i++)
		scanf("%lld",&arr1[i]);
		for(i=0;i<n;i++){
		scanf("%lld",&arr2[i]);sum+=arr1[i]*arr2[i];}
		long long int final_sum=sum;
		for(int i=0;i<n;i++)
            final_sum=max(final_sum ,sum+abs(k*arr2[i]));
		printf("%lld\n",final_sum);
	}
	return(0);
}
