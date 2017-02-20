#include<bits/stdc++.h>
using namespace std;

template <typename  T>
void print(T *A,bool *B,int low,int high,int size){


	if(low>high){

	    cout<<"(";
		for(int i=0;i<size;i++){

			if(B[i])cout<<" "<<A[i];
		}
		cout<<")\n";
	}
	else{


		B[low]=true;
		print(A,B,low+1,high,size);
		B[low]=false;
		print(A,B,low+1,high,size);
	}
	return ;
}
int main(){

	int test;
	cin>>test;

	while(test--){
		int size;
		cout<<"Size : ";
		cin>>size;

		char *A=(char *)malloc(size*sizeof(char));

		cout<<" Array : ";
		for(int i=0;i<size;i++){

			cin>>A[i];
		}
		bool *B=(bool *)malloc(size*sizeof(bool));

		for(int i=0;i<size;i++) {

			B[i]=false;
		}
		print(A,B,0,size-1,size);
		cout<<endl;
	}

	return 0;
}