#include<bits/stdc++.h>
using namespace std;

int main(){


	int size;

	cout<<"Size  : ";
	cin>>size;


	int *A =(int *)malloc(size*sizeof(int));

	cout<<"Array : ";
	for(int i=0;i<size;i++){

		cin>>A[i];
	}

	int *Lmin=(int*)malloc(size*sizeof(int));
	int *Rmax=(int*)malloc(size*sizeof(int));

	Lmin[0]=A[0];

	for(int i=1;i<size;i++){

		Lmin[i]=min(Lmin[i-1],A[i]);
	}

	Rmax[size-1]=A[size-1];


	for(int i=size-2;i>=0;i--){

		Rmax[i]=max(Rmax[i+1],A[i]);
	}


	int mx=0;

	int i=0;
	int j=0;

	while(i<size && j<size){


		if(Lmin[i]<Rmax[j]){

			mx=max(mx,j-i);
			j+=1;
		}
		else i+=1;
	}

	cout<<mx<<endl;
}