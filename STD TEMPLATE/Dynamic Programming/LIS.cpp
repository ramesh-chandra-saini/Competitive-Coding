#include<bits/stdc++.h>
using namespace std;

/*
* length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.*
*/
void Lis(int *A,int N)
{

	int *dp=(int*)malloc((N+1)*sizeof(int));

    for(int i=0;i<N;i++){

		dp[i]=1;
    }
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){

			if(A[j]<A[i])
				dp[i]=max(dp[i],dp[j]+1);
		}
		for(int k=0;k<N;k++) cout<<dp[k]<<" "; cout<<endl;
	}
	int mx=1;
	for(int i=0;i<N;i++)
		mx=max(mx,dp[i]);
	cout<<mx<<endl;
	return;
}
int main()
{

	int test;
	cout<<"Test : ";
	cin>>test;

	while(test--){

		int size;
		cout<<"Size : ";
		cin>>size;

		int *A=(int*)malloc(size*sizeof(int));
		cout<<"Array : ";

		for(int i=0;i<size;i++)
		cin>>A[i];

		Lis(A,size);
	}
	return 0;
}