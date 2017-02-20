#include<bits/stdc++.h>
using namespace std;
void count(int a[],int n, int expo){


	int ct[n];

	for(int i=0;i<n;i++) ct[i]=0;

	for(int i=0;i<n;i++){

		ct[(a[i]/expo)%n]++;
		cout<<(a[i]/expo)%n<<" ";
	}
	cout<<endl;

	for(int i=1;i<n;i++){

		ct[i]+=ct[i-1];
	}

	int output[n]={0};

	for(int i=n-1;i>=0;i--){

		output[ct[((a[i]/expo)%n) ]-1]=a[i];
		ct[(a[i]/expo)%n]--;

	}
	for(int i=0;i<n;i++) a[i]=output[i];
	cout<<"partial : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;

}
void linearSort(int a[],int n)
{

	count(a,n,1);
	count(a,n,n);
}
int main()
{

	int test;
	cin>>test;


	while(test--){


		int n;
		cout<<"Size :  ";
		cin>>n;

		int a[n];

		cout<<"Array : ";
		for(int i=0;i<n;i++) cin>>a[i];

		linearSort(a,n);

		//
		for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
	}

	return 0;
}