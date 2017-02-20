#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<cstdlib>
#include<string>
static bool _comp(string a,string b)
{

	return (a+b>=b+a)? true:false;
}
string num2string(int num)
{

	ostringstream os;
	os.clear();
	os<<num;
	return os.str();
}
string largestNumber(const vector<int> &A)
{

	int n=A.size();
    vector<string> Copy;
    string temp;
    temp.clear();
    for(int i=0;i<n;i++){


		Copy.push_back(num2string(A.at(i)));
    }

    sort(Copy.begin(),Copy.end(),_comp);

	string ans;
	ans.clear();
    if(Copy.at(0)=="0"){

		ans+='0';
		return ans;
    }


   for(int i=0;i<n;i++){

	   ans+=Copy.at(i);
   }

   return ans;
}
int main()
{
   vector<int> Vec;
   int size,value;
   cout<<"Input"<<endl;
   cout<<"Enter Array Size ";
   cin>>size;

   for(int i=0;i<size;i++){

		cin>>value;
         Vec.push_back(value);
   }

	cout<<"Output"<<endl;
	cout<<largestNumber(Vec);

  return 0;
}