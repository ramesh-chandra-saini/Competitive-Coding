#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *A,int size){

	int write=0;
	int comp=0;
	int step=1;
	for(int i=0;i<size-1;i++){

		for(int j=i+1;j<size;j++){

			comp++;
			if(A[i]>=A[j]){

				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;

				write+=3;
			}
		}
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
		cout<<"Size : ";
		cin>>size;

		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Array : ";
		for(int i=0;i<size;i++){


			cin>>A[i];
		}
		selectionSort(A,size);
		cout<<"\n**************Sorted Data*********************************\n";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}