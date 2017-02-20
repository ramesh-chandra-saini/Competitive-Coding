
#include<bits/stdc++.h>
using namespace std;

void _mergesort(int arr[],int low,int mid,int high)
{
	 int *temp=(int*)malloc((high)*sizeof(int));
       // temporary array
	int i=0;
	int j=low;
	int m=mid+1;

	while(j<=mid && m<=high){

		//choose small element  in both halves
		if(arr[j]<=arr[m]){

			temp[i++]=arr[j++];
		}
		else{
			temp[i++]=arr[m++];
		}
	}

    //both halves may not be equal

	if(j>mid){

		//copy till end of second half
		while(m<=high){

			temp[i++]=arr[m++];
		}
	}
	else{

		//copy till end of first half
		while(j<=mid){

			temp[i++]=arr[j++];
		}
	}

    //copy to back into original array
	for(j=low,i=0;j<=high;j++,i++){
		arr[j]=temp[i];
	}
	return ;
}
void _merge(int arr[],int low,int high)
{
	if(low>=high)return; //Base case : single Element or Invalid Index

	int mid=(high+low)/2;

	_merge(arr,low,mid);
	_merge(arr,mid+1,high);

	_mergesort(arr,low,mid,high);

	return ;
}
int main()
{

	int arr[]={38,27,43,3,9,82,10};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<"INPUT : "<<endl;
	for(int i=0;i<n;i++){

		cout<<arr[i]<<",";
	}
	cout<<endl;

     //here is call to function
	_merge(arr,0,n-1);

	cout<<"OUTPUT : "<<endl;
	for(int i=0;i<n;i++){

		cout<<arr[i]<<",";
	}
	cout<<endl;

	return 0;
}