#include<bits/stdc++.h>
using namespace std;

int main(){


	int size;
	cout<<"Size : ";
	cin>>size;

	int *A=(int *)malloc((1+size)*sizeof(int));

	cout<<"Array : ";
	for(int i=1;i<=size;i++){

		cin>>A[i];
	}

	for(int i=1;i<=size;i++){

		if(A[A[i]]>0){
			A[A[i]]=-A[i];
		}
		else {

			cout<<"Duplicate : "<<A[i]<<endl;
		}

		for(int k=1;k<=size;k++){

			cout<<A[k]<<" ";
		}
		cout<<endl;

	}

	return 0;
}