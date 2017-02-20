#include<bits/stdc++.h>
using namespace std;

int step=0;
void Sort(int *A,int low,int mid,int high,int *temp){

	int j=low,m=mid+1,i=low;

	cout<<step++<<").";
	for(int k=low;k<=mid;k++){

		cout<<A[k]<<" ";
	}
	cout<<",";
	for(int k=mid+1;k<=high;k++){

		cout<<A[k]<<" ";
	}
	cout<<"::";

	while(j<=mid && m<=high){

		if(A[j]<=A[m]){

			temp[i++]=A[j++];
		}
		else {

			temp[i++]=A[m++];
		}
	}

	while(j<=mid){

		temp[i++]=A[j++];
	}

	while(m<=high){

		temp[i++]=A[m++];
	}

	for(i=low;i<=high;i++){

		A[i]=temp[i];
	}


	for(int i=low;i<=high;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;

	return;
}
void mergeSort(int *A,int low,int high,int *temp){

	if(low>=high) return;

	int mid=low+(high-low)/2;

	mergeSort(A,low,mid,temp);
	mergeSort(A,mid+1,high,temp);

	Sort(A,low,mid,high,temp);

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
		int *temp=(int*)malloc(size*sizeof(int));
		cout<<"Array : ";
		for(int i=0;i<size;i++){


			cin>>A[i];
		}
		mergeSort(A,0,size-1,temp);
		cout<<"Sorted Data : ";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
}