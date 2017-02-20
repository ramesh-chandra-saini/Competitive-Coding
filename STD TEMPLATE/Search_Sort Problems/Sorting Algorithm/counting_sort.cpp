/*
* counting sort*
* time complexity : O(n+k)*
* space complexity : O(k)*
*only useful when given range of input is very small*
*work only for positive integer (generally)*
*to work with negative number we have to make a shift should be done*
*/
#include<bits/stdc++.h>
using namespace std;

void Count(vector<int>&V,int size)
{
    if(size<=1) return;
	int L=V.at(0),R=V.at(0);
	for(size_t i=1;i<size;i++){

		L=min(L,V.at(i));
		R=max(R,V.at(i));
	}
	int shift=0;
	if(L<0){

        shift=L;
		for(size_t i=0;i<size;i++){

			V.at(i)+=-L;
		}
		R+=-L;
		L=0;
	}
	// range [L,R]
	vector<int> ct(R+1-L,0);
	for(size_t i=0;i<size;i++){

		ct.at(V.at(i)-L)++;
	}

	for(size_t i=1;i<=R-L;i++){

		ct.at(i)+=ct.at(i-1);
	}

    vector<int> output(size,0);
     int index=0;
    cout<<size<<endl;
    for(int i=size-1;i>=0;i--){

			index=ct.at(V.at(i)-L);
			output.at(index-1)=V.at(i);
			ct.at(V.at(i)-L)--;
   }
   for(int i=0;i<size;i++){

		V.at(i)=output.at(i)+shift;
   }


}
//driver program
int main()
{
	int size,val;
	cout<<"Enter the size of input"<<endl;
	cin>>size;

	cout<<"Input : ";
	vector<int> Vec;

	for(size_t i=0;i<size;i++){


		cin>>val;
		Vec.push_back(val);
	}
	Count(Vec,size);

    cout<<"Output : ";
	for(size_t i=0;i<size;i++){

		cout<<Vec.at(i)<<" ";
	}
	cout<<endl;

    return 0;
}