#include<bits/stdc++.h>
using namespace std;


///wave form:  if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

/// Eg.  Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
/// Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR {20, 5, 10, 2, 80, 6, 100, 3};

void waveSort(int a[],int n){

	int j=1;
	for(int i=0;i<n-1;i++){

		    j=max(j,i+1);

		if(i%2==0){

			if(a[i]>=a[i+1]);
			else {


				while(j<n && a[j]<a[i]) j++;
				//cout<<i<<"<-->"<<j<<endl;
				if(j==n) j--;

				int swp=a[i];
				a[i]=a[j];
				a[j]=swp;
			}
		}
		else{

			if(a[i]<=a[i+1]);
			else{

				while(j<n && a[j]>a[i]) j++;
				if(j==n) j--;

				int swp=a[i];
				a[i]=a[j];
				a[j]=swp;
			}
		}
		cout<<"("<<i<<","<<j<<") :: "<<a[i]<<"<-->"<<a[j]<<" : ";
		for(int i=0;i<n;i++){

			cout<<a[i]<<" ";
		}
			cout<<endl;
	}

	return;
}
int main(){

	int test;
	cin>>test;

    cout<<"arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= ….."<<endl;
	while(test--){


		int n;
		cout<<"size :";
		cin>>n;

		int a[n];

		for(int i=0;i<n;i++) cin>>a[i];

		waveSort(a,n);

		for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
	}

	return 0;
}