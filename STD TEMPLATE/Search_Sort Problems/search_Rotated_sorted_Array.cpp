#include<bits/stdc++.h>
using namespace std;

int search(int *A,int low,int high,int key){

	if(low>high) return -1;

	int mid=(high+low)/2;

	if(A[mid]==key) return mid;

	if(A[low]<=A[mid]){

		if(A[low]<=key && key<A[mid])
			return search(A,low,mid-1,key);
		return search(A,mid+1,high,key);
	}
	if(A[mid]<key && key<=A[high])
		return search(A,mid+1,high,key);
	return search(A,low,mid-1,key);

}
int main(){


	int size;
	cout<<"Size : ";
	cin>>size;

	int *A=(int *)malloc((1+size)*sizeof(int));

	cout<<"Array : ";
	for(int i=0;i<size;i++){

		cin>>A[i];
	}

	int key;
	cout<<"Key : ";
	cin>>key;
	int ind;
	if((ind=search(A,0,size-1,key))==-1) cout<<"Result Not Found"<<endl;
	else cout<<key<<" @ "<<ind<<endl;

	return 0;
}