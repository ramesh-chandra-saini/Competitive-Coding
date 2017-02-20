#include<bits/stdc++.h>
using namespace std;

void countSort(int *A,int size){

	int mn=A[0];
	int mx=A[0];
	for(int i=1;i<size;i++){

		mn=min(mn,A[i]);
		mx=max(mx,A[i]);
	}

    for(int i=0;i<size;i++){

		A[i]-=mn;
    }
    cout<<"Actual Range : ["<<mn<<" "<<mx<<"]"<<endl;
    cout<<"Improved Range : [0 "<<mx-mn<<"]"<<endl;
	cout<<"Derived Data :";
	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;
    int R=mx-mn+1;
    int Count[R];

    for(int i=0;i<R;i++){

		Count[i]=0;
    }

    for(int i=0;i<size;i++){


		Count[A[i]]++;
    }

    cout<<"Count"<<endl;
    for(int i=0;i<R;i++){

		cout<<i<<" ";
    }
    cout<<endl;

	for(int i=0;i<R;i++){

		cout<<Count[i]<<" ";
	}
	cout<<endl;

	for(int i=1;i<R;i++){

		Count[i]+=Count[i-1];
	}

	for(int i=0;i<R;i++){

		cout<<Count[i]<<" ";
	}
	cout<<endl;

	int output[size];
	for(int i=size-1;i>=0;i--){

		int ind=Count[A[i]];

		output[ind-1]=A[i];
		Count[A[i]]--;
	}

	for(int i=0;i<size;i++){

		A[i]=output[i];
	}

    cout<<"Derived Sorted Data :";
	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<size;i++){

		A[i]+=mn;
    }
    cout<<"Original Sorted  Data : ";

	for(int i=0;i<size;i++){

		cout<<A[i]<<" ";
	}
	cout<<endl;
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

		int *A=(int *)malloc(size*sizeof(int));

		cout<<"Data : ";
		for(int i=0;i<size;i++){

			cin>>A[i];
		}
		countSort(A,size);
		cout<<"Sorted Data :";
		for(int i=0;i<size;i++){

			cout<<A[i]<<" ";
		}
		cout<<endl;


	}
	return 0;
}
