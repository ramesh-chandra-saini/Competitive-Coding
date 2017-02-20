/*
*For two strings A and B, we define the similarity of the strings to be the length of the longest prefix common to both strings*
*For example, the similarity of strings “abc” and “abd” is 2, while the similarity of strings “aaa” and “aaab” is 3.*
*Calculate the sum of similarities of a string S with each of it’s suffixes.*
*Time Complexity : O(N^2)*
*Space Complexity : O(1) *
*/


#include<bits/stdc++.h>
using namespace std;
int similarity(string str,int i,int n)
{

    int j=i;
    int sim=0;
	for(int i=0;j<n;i++){

		if(str.at(i)==str.at(j)){

			sim++;
			j++;
		}
		else break;
	}
	return sim;
}
int main()
{

	int test;
	cin>>test;

	while(test--){


		string str;
		cin>>str;
		int n=str.length();
		int sum=0;
		for(int i=0;i<n;i++){

			sum+=similarity(str,i,n);
		}
		cout<<sum<<endl;
	}

}