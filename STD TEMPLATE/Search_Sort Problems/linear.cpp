///given data Range [0,n^3-1]
#include<bits/stdc++.h>
using namespace std;

void count(int *A,int size,int expo){

	int CT[size];

	for(int i=0;i<size;i++){

		CT[i]=0;
	}

	for(int i=0;i<size;i++){

		CT[(A[i]/expo)%size]++;
	}

	for(int i=1;i<size;i++){

		CT[i]+=CT[i-1];
	}

	int output[size];
	for(int i=size-1;i>=0;i--){

		output[CT[((A[i]/expo)%size)]-1]=A[i];
		CT[((A[i]/expo)%size)]--;
	}
	for(int i=0;i<size;i++){

		A[i]=output[i];
	}

	return;
}

int step=1;
void radixsort(int *A,int size){

	count(A,size,1);
	cout<<step++<<").";

	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	count(A,size,size);
	cout<<step++<<").";
	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	count(A,size,size*size);
	cout<<step++<<").";
	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	return ;
}

int main(){

	int size;
	cout<<"size :";
	cin>>size;

	int *A=(int*)malloc(size*sizeof(int));


	for(int i=0;i<size;i++){

		cin>>A[i];
	}

	cout<<"Sorted Data : ";
	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	radixsort(A,size);

}