/*
*Not good time complexity that's why second approach came into picture*
*Approach : B) Merge Technique *
*Time Complexity : O(nlogn) *
*Space Complexity : O(n) *
*/


#include<bits/stdc++.h>
using namespace std;

int countInv(int A[], int *temp,int low,int mid,int high){

	int inversion=0;
	int i=low;
	int j=low;
	int m=mid+1;

	while(j<=mid && m<=high ){


		if(A[j]<=A[m]){

			temp[i++]=A[j++];
		}
		else{
		    inversion+=(mid+1-j);
			temp[i++]=A[m++];
		}
	}
	while(j<=mid){
		temp[i++]=A[j++];
	}
	while(m<=high){

		temp[i++]=A[m++];
	}
	for(int i=low;i<=high;i++){

		A[i]=temp[i];
	}
	return inversion;
}
int merge(int A[],int *temp, int low,int high){


	if(low>=high) return 0;
	int inversion=0;
	int mid=(low+high)/2;
	inversion= merge(A,temp,low,mid);
	inversion+= merge(A,temp,mid+1,high);

	inversion+= countInv(A,temp,low,mid,high);
   return inversion;
}
int countInversions(int A[],int size) {

	int *temp=(int*)malloc(size*sizeof(int));

	return merge(A,temp,0,size-1);
}
int main(){

 int arr[]={3,1,4,5,2};//Given array

           int n=sizeof(arr)/sizeof(arr[0]);//Get number of element in array


		cout<<countInversions(arr,n)<<endl;
	return 0;
}
/********************************END OF CODE**********************************/