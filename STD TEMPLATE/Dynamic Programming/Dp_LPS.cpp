/*find longest palindrome substring*/
/*Approach : Dynamic Programming*/
#include<bits/stdc++.h>
using namespace std;
string LPS(string str){


   int n=str.length();
  //mamoization
   int table[n][n];
   //intialization
   for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){

			table[i][j]=0;
		}
   }
  // string length one string are always palindrome
   for(int i=0;i<n;i++){

       table[i][i]=1;
   }
   int start=0,maxlength=1,flag=1;
   //check for palindromic substing of length of 2
   for(int i=0;i<n-1;i++){

	    if(str[i]==str[i+1]){

	       table[i][i+1]=1;
	       if(flag==0){

				start=i;
				maxlength=2;
	       }
	    }
   }
   for(int k=3;k<=n;k++){

	for(int i=0;i<=n-k;i++){


	   //where j is least character of substring
	   int j=i+k-1;
	    if(table[i+1][j-1] && str[i]==str[j]){

	        table[i][j]=1;
	        if(k>maxlength){

	           start=i;
	           maxlength=k;
	        }
	    }
	}
   }
   return str.substr(start,maxlength);

}
int main()
{

   cout<<"Enter test case :";
   int test;
   string str;
   cin>>test;
   while(test--){
	cout<<"Enter your string : ";
	 str.clear();
	cin>>str;
	cout<<LPS(str)<<endl;
	}
}