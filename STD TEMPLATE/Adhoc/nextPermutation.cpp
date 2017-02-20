/*given sequence make next permutation */

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {


	//to find is any element is greater from any element behind it....nums[i]<nums[i+1];
	int k=-1;
	int n=nums.size();
	//size of vector

	for(int i=0;i<n-1;i++){


		//we can get so many pair why not break loop after getting a pair because
		//we want to maximum index which hold nums[i]<nums[i+1]..
		// It is lead to minimum changes in permutation

		// why we do not compare all pair?  why consecutive pair only ?
		// because if any element pair exist then we will go for minimum index pair later  see@***
		//This help to reduce complexity to O(N^2) to O(N)....

		if(nums.at(i)<nums.at(i+1)){
			k=i;
			//update k value with latest index which hold condition
		}
	}

	//this case show no two element exist which can hold nums[i]<nums[i+1];

	if(k==-1){

		//then go for first permutation just simple sort
		// ex. 5 4 3 2 1  -> 1 2 3 4 5
		sort(nums.begin(),nums.end());
		return;
	}

	//this case show that given permutation is not last possible permutation  1 3 2 4 5  -> 1 3 2 5 4
	int l=k+1;

	// *** //
	for(int i=k+1;i<n;i++)
	{
		if(nums.at(i)>nums.at(k)){
			l=i;
		}
	}

	//swap needed to make next permutation
	// we have not  ensured till now ...resultant permutation is next to given permution or next to next who knows??
	// don't worry we will see....

	swap(nums.at(l),nums.at(k));

	//why sorting is needed
	//ex : 1 2 5 4 3   after swapping :-> 1 3 5 4 2 : -> not next permutation
	//many permutation has left between :-> 1 3 2 4 5 , 1 3 2 5 4 ,1 3 4 2 5, 1 3 4 5 2 , 1 3 5 2 4
	// then sorting is needed 1 3 2 4 5
	// sorting start after lefting  k point from start
	//why till end ??think.................

	sort(nums.begin()+k+1,nums.end());
	return;
}

//driver function
int main(){

	int n;
	cout<<"Input "<<endl;
	cout<<"size : ";
	cin>>n;
	cout<<"Array : ";
	vector<int> num;
	for(int i=0;i<n;i++){

		int temp;
		cin>>temp;
		num.push_back(temp);
	}

    //function to generate next permutation...
	nextPermutation(num);


	cout<<"Output : ";
	for(int i=0;i<n;i++){

		cout<<num.at(i)<<" ";
	}

	return 0;
}
