#include<bits/stdc++.h>
using namespace std;
int step=1;
void Sort(int *A,int size,int expo){


	int count[10];

	for(int i=0;i<10;i++){

		count[i]=0;
	}

	for(int i=0;i<size;i++){

		count[(A[i]/expo)%10]++;
	}
	for(int i=1;i<10;i++){

		count[i]+=count[i-1];
	}

	int *output=(int*)malloc(size*sizeof(int));

	for(int i=size-1;i>=0;i--){

		output[count[((A[i]/expo)%10)]-1]=A[i];
		count[(A[i]/expo)%10]--;
	}
	for(int i=0;i<size;i++){

		A[i]=output[i];
	}

	cout<<step++<<").";
	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	return;
}

void radixSort(int *A,int size){

	int mx=A[0];
	int mn=A[0];

	for(int i=1;i<size;i++){

		mx=max(mx,A[i]);
		mn=min(mn,A[i]);
	}

	cout<<"["<<mn<<","<<mx<<"] : ";
	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<size;i++){

		A[i]-=mn;
	}

	mx=A[0];
	for(int i=1;i<size;i++){

		mx=max(mx,A[i]);
	}

	cout<<"[0"<<","<<mx<<"] : ";

	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	int D=0;
	while(mx){

		D++;
		mx/=10;
	}

	int expo=1;
	for(int i=0;i<D;i++){

		Sort(A,size,expo);
		expo=expo*10;
	}

	for(int i=0;i<size;i++){

		A[i]+=mn;
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

		step=1;
		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Data : ";
		for(int i=0;i<size;i++){

			cin>>A[i];
		}
		radixSort(A,size);
		cout<<"Sorted Data :";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;


	}
	return 0;
}
