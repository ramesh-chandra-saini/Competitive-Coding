#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int *A,int low,int high,int key){

	if(low>high) return -1;

	int mid=low+(high-low)/2;

	if(A[mid]==key) return mid;
	if(key<A[mid]) return BinarySearch(A,low,mid-1,key);
	return BinarySearch(A,mid+1,high,key);
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
		sort(A,A+size);
		for(int i=0;i<size;i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
		int key;
		cout<<"Key : ";
		cin>>key;

		int index=BinarySearch(A,0,size-1,key);
		if(index==-1) cout<<"ERROR :  404\nResult Not Found"<<endl;
		else cout<<"key @ "<<index<<endl;
	}
	return 0;
}
