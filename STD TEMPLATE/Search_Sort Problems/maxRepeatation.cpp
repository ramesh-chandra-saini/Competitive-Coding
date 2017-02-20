#include<bits/stdc++.h>
using namespace std;

int main(){


	int size;
	cout<<"Size : ";
	cin>>size;

	int *A=(int *)malloc((1+size)*sizeof(int));

	cout<<"Array : ";
	for(int i=0;i<size;i++){

		cin>>A[i];
	}

	for(int i=0;i<size;i++){

		A[(A[i])%size-1]+=size;
	}

	for(int i=0;i<size;i++){
		cout<<A[i]/size<<endl;
	}

	return 0;
}