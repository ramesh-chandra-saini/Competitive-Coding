#include<bits/stdc++.h>
using namespace std;

void LCS(string A,string B){

	int a=A.length();
	int b=B.length();

	int i,j;
	int dp[a+1][b+1];

	for( i=0;i<=a;i++)
		dp[i][0]=0;
	for(j=0;j<=b;j++)
		dp[0][j]=0;

	for( i=1;i<=a;i++){

		for(j=1;j<=b;j++){

			if(A[i-1]==B[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	for(i=0;i<=a;i++){

		for(j=0;j<=b;j++){

			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"L : "<<dp[a][b]<<endl;
	i=a;
	j=b;

	string ans; ans.clear();

	while(i>0 && j>0){

		if(A[i-1]==B[j-1]){
			ans+=A[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else j--;
	}

	int l=ans.length();

	for(int i=0;i<l/2;i++){

		char ch=ans.at(i);
		ans.at(i)=ans.at(l-1-i);
		ans.at(l-1-i)=ch;
	}
	cout<<"Subsequence : "<<ans;
}
int main(){


	int test;
	cout<<"Test : ";
	cin>>test;

	while(test--){

		string A,B;
		cin>>A>>B;

		LCS(A,B);
	}
	return 0;
}