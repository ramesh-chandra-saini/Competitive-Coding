#include<bits/stdc++.h>
using namespace std;

void bucketSort(vector<float> &V, int size)
{

	//create an empty bucket...
    vector<float> B[size];

    //put item into bucket
	for(int i=0;i<size;i++){

		int index=size*V.at(i);
		B[index].push_back(V.at(i));
	}

	// now time to sort individual
	for(int i=0;i<size;i++){

		sort(B[i].begin(),B[i].end());
	}

	V.clear();
	//put back all element into original place
	for(int i=0;i<size;i++){

		for(int j=0;j<B[i].size();j++)
		{

			V.push_back(B[i][j]);
		}
	}

	return ;
}
int main()
{

	cout<<"INPUT "<<endl;
	int size;
	cout<<"Size :";
	cin>>size;
	vector<float> V;
	float value;
	for(int i=0;i<size;i++){

		cin>>value;
		V.push_back(value);
	}
	//cal for sort
	bucketSort(V,size);

	cout<<"OUTPUT "<<endl;
	for(int i=0;i<size;i++){

		cout<<V.at(i)<<" ";
	}
	cout<<endl;

	return 0;
}