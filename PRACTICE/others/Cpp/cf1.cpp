#include<bits/stdc++.h>
using namespace std;

int main(){


	int n;
	cin >> n;
	char arr[n][n];

	for(int i=0;i<n;i++)
		scanf("%s",arr[i]);
	long long int ans=0;
	for(int i=0;i<n;i++){

		int ct=0;
		for(int j=0;j<n;j++)
			if(arr[i][j]=='C')
					ct++;
		ans+=(ct*(ct-1))/2;
	}
	for(int i=0;i<n;i++){

		int ct=0;
		for(int j=0;j<n;j++)
			if(arr[j][i]=='C')
				ct++;
		ans+=(ct*(ct-1))/2;
	}
	cout<<ans<<endl;
}
