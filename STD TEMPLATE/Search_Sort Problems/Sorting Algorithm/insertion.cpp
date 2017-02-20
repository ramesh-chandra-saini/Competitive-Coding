#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *A,int size){

	int write=0;
	int comp=0;
	int step=1;
	for(int i=1;i<size;i++){

		int temp=A[i];
		int j=i-1;

		while(j>=0 && temp<A[j]){

			A[j+1]=A[j];
			j--;
			write++;
		}
		A[j+1]=temp;

		cout<<step++<<").";
		for(int k=0;k<size;k++){

			cout<<A[k]<<" ";
		}
		cout<<endl;
	}
	cout<<"Memory write : "<<write<<endl;
	cout<<"Comparision : "<<comp<<endl;
	return ;
}

//driver function............
int main(){


	int test;
	cout<<"Test : ";
	cin>>test;

	while(test--){


		int size;
		cout<<"\nSize : ";
		cin>>size;

		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Array : ";
		for(int i=0;i<size;i++){


			cin>>A[i];
		}
		selectionSort(A,size);
		cout<<"Sorted Data : ";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}