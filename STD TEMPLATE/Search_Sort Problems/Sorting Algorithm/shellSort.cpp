
//O(N(logN)^2)..
#include<bits/stdc++.h>
using namespace std;
int step=1;

void shellSort(int *A,int size){

	for(int gap=size/2;gap>0;gap/=2){


		for(int i=gap;i<size;i++){

			int temp=A[i];
			int j;
			for(j=i;j>=gap && A[j-gap]>temp;j-=gap){
				A[j]=A[j-gap];
			}
			A[j]=temp;
		}
		cout<<step++<<").";

		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return ;
}
int main(){

	int test;
	cout<<"Test : ";
	cin>>test;

	while(test--){

		int size;
		cout<<"Size : ";
		cin>>size;

		step=1;
		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Data : ";
		for(int i=0;i<size;i++){

			cin>>A[i];
		}
		shellSort(A,size);
		cout<<"Sorted Data :";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
