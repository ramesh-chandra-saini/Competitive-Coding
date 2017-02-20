#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *A,int size){

	int write=0;
	int comp=0;
	int step=1;
	for(int i=0;i<size-1;i++){

		bool swp=false;
		for(int j=0;j<size-1;j++){

			comp++;
			if(A[j]>=A[j+1]){

				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;

				write+=3;
				swp=true;
			}
		}
		if(!swp) break;
		cout<<step++<<").";
		for(int k=0;k<size;k++){

			cout<<A[k]<<" ";
		}
		cout<<endl;
	}
	cout<<"Memory write : "<<write<<endl;
	cout<<"Comparision : "<<comp<<endl;
	return ;
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

		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Array : ";
		for(int i=0;i<size;i++){


			cin>>A[i];
		}
		selectionSort(A,size);
		cout<<"Sorted Data : ";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
