#include<bits/stdc++.h>
using namespace std;

int main(){

	int size;
	cout<<"Size : ";
	cin>>size;

	int size2;

	cout<<"Size2 : ";
	cin>>size2;

	int *A=(int *)malloc((size2+size)*sizeof(int));
	int *B=(int *)malloc((size2)*sizeof(int));


	cout<<"A :";
	for(int i=0;i<size;i++){

		cin>>A[i];
	}
	sort(A,A+size);

	cout<<"B : ";
	for(int i=0;i<size2;i++){

		cin>>B[i];
	}
	sort(B,B+size2);

	int j=size-1;
	int m=size2-1;
	int k=size+size2-1;
	while(j>=0 && m>=0){

		if(A[j]>=B[m]){

			A[k]=A[j];
			k--;
			j--;
		}
		else{

			A[k]=B[m];
			k--;
			m--;
		}
	}

	while(m>=0){

		A[k]=B[m];
		k--;
		m--;
	}
	while(j>=0){


		A[k]=A[j];
		j--;
		k--;
	}

	cout<<"Sorted Data : ";
	for(int i=0;i<size+size2;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	return 0;
}