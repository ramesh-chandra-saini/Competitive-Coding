#include<bits/stdc++.h>
using namespace std;

void BucketSort(float *A,int size){

	vector<float> B[size];
	cout<<"val : ";
	for(int i=0;i<size;i++){

		int val= A[i]*size;
		cout<<val<<" ";
		B[val].push_back(A[i]);
	}
	cout<<endl;

	cout<<"Bucket  "<<endl;
	for(int i=0;i<size;i++){

		for(vector<float> :: iterator  it=B[i].begin();it!=B[i].end();++it){

			cout<<*it<<" ";
		}
		cout<<endl;
	}


	for(int i=0;i<size;i++){

		sort(B[i].begin(),B[i].end());
	}
	cout<<"Sorted Bucket  "<<endl;
	for(int i=0;i<size;i++){

		for(vector<float> :: iterator  it=B[i].begin();it!=B[i].end();++it){

			cout<<*it<<" ";
		}
		cout<<endl;
	}

	int j=0;
	for(int i=0;i<size;i++){

		for(vector<float> :: iterator  it=B[i].begin();it!=B[i].end();++it){

			A[j++]=*it;
		}
	}
	return;
}
int main(){

	int test;
	cout<<"Test : ";
	cin>>test;

	while(test--){

		int size;
		cout<<"Size : ";
		cin>>size;

		float *A=(float *)malloc(size*sizeof(float));

		cout<<"Data : ";
		for(int i=0;i<size;i++){

			cin>>A[i];
		}
		BucketSort(A,size);
		cout<<"Sorted Data :";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;


	}
	return 0;
}
