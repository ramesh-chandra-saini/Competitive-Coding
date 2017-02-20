#include<bits/stdc++.h>
using namespace std;

void heapify(int *A,int size){

	for(int i=0;i<=size;i++){


	    int child=i;

		while(child){

			int parent=child/2;

			if(A[child]>A[parent]){

				int swp=A[child];
				A[child]=A[parent];
				A[parent]=swp;
			}
			child/=2;
		}
	}
	return;
}
int main(){

	int test;
	cout<<"Test : ";
	cin>>test;

	while(test--){

		int size;
		cout<<"Size : ";
		cin>>size;

		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Data : ";
		for(int i=0;i<size;i++){

			cin>>A[i];
		}
		int step=1;
		cout<<"Heapify : "<<endl;
		for(int j=1;j<size;j++){

			heapify(A,j);

			cout<<step++<<").";
			for(int i=0;i<size;i++){

				cout<<A[i]<<" ";
			}
			cout<<endl;
		}
		cout<<"Heapsort : "<<endl;
		step=1;


		for(int j=0;j<size-1;j++){

			int swp=A[0];
			A[0]=A[size-1-j];
			A[size-1-j]=swp;

			heapify(A,size-1-j-1);

			cout<<step++<<").";
			for(int i=0;i<size;i++){

				cout<<A[i]<<" ";
			}
			cout<<endl;

		}

		cout<<"Sorted Data :";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;


	}
	return 0;
}
