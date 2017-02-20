#include<bits/stdc++.h>
using namespace std;
void shellSort(int a[],int n)
{

	for(int gap=n/2;gap>0;gap/=2){

		for(int i=gap;i<n ; i++){

			int temp=a[i];
            int j;
			for(j=i;j>=gap && a[j-gap]>temp;j-=gap)
				a[j]=a[j-gap];

			a[j]=temp;
		}
	}
       for(int i=0;i<n;i++){

			cout<<a[i]<<" ";
       } cout<<endl;
	return;
}
int main()
{
	int test;
	cin>>test;

	while(test--){


		int n;
		cout<<"Size : ";
		cin>>n;
		cout<<"Array : ";
		int a[n];


		for(int i=0;i<n;i++) cin>>a[i];

		shellSort(a,n);
	}
	return 0;
}