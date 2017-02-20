/*
*radix sorting *
*complexity : O(n*r)*
*space complexity : O(1)*
* only for positive numbers*
*/
#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> &V,int size, int fact)
{
	vector<int> count(10,0);

	for(size_t i=0;i<size;i++){

		count.at((V.at(i)/fact)%10)++;
	}

	for(size_t i=1;i<10;i++){

		count.at(i)+=count.at(i-1);
	}

	vector<int> output(size,0);
	for(int i=size-1;i>=0;i--){

        int index=((V.at(i)/fact)%10);
		output.at(count.at(index)-1)=V.at(i);
		count.at(index)--;
	}

	// make copy to original array
	for(size_t i=0;i<size;i++){

		V.at(i)=output.at(i);
	}
}
void Radix(vector<int> &V,int size)
{
    if(size<=1) return;
	int mx=V.at(0);
	for(size_t i=1;i<size;i++){

		mx=max(mx,V.at(i));
	}
	int digit=0;

	while(mx){

		digit++;
		mx/=10;
	}
	int fact=1;
	for(int i=0;i<digit;i++){

		sort(V,size,fact);
		fact*=10;
	}
	return ;
}
 //driver program
int main()
{
    int t;
    cin>>t;
    while(t--){
	int size,val;
	cout<<"Enter the size : "<<endl;
	cin>>size;

	vector<int> Vec;
	for(size_t i=0;i<size;i++){
		cin>>val;
		Vec.push_back(val);
	}
	Radix(Vec,size);

	cout<<"sorted element ";
	for(size_t i=0;i<size;i++){

		cout<<Vec.at(i)<<" ";
	}
	cout<<endl;
  }
    return 0;
}
