#include<bits/stdc++.h>
using namespace std;


//mid point as pivot
int step=0;
int partition(int *A,int low,int high){


	int pivot=A[]low;
	int j=low;
	for(int i=low+1;i<=high;i++)
	{

		if(A[i]<=A[pivot]){

			int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			j++;
		}
	}

	int swp=A[j];
	A[j]=A[pivot];
	A[pivot]=swp;
	return j;
}
void quickSort(int *A,int low,int high){

	if(low>=high) return;
	int pindex=partition(A,low,high);

	quickSort(A,low,pindex-1);
	quickSort(A,pindex+1,high);

	return;
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
		step=0;

		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Array : ";
		for(int i=0;i<size;i++){


			cin>>A[i];
		}
		quickSort(A,0,size-1);
		cout<<"Sorted Data : ";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
}