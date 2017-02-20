#include<bits/stdc++.h>
using namespace std;

int main(){


	int S,N;

	cin>>S>>N;

	int W[N+1],V[N+1];
	for(int i=1;i<=N;i++){

		cin>>W[i]>>V[i];
	}

	int dp[N+1][S+1];
	for(int i=0;i<=S;i++)
		dp[0][i]=0;

    for(int i=0;i<=N;i++)
		dp[i][0]=0;
	for(int i=1;i<=N;i++){

		for(int w=0;w<=S;w++){

			if(w<W[i]){

				dp[i][w]=dp[i-1][w];
			}
			else{

				dp[i][w]=max(dp[i-1][w],(dp[i-1][w-W[i]]+V[i]));
			}
		}
	}

	/*for(int i=0;i<=N;i++){

		for(int w=0;w<=S;w++){

			cout<<dp[i][w]<<" ";
		}
		cout<<endl;
	}
*/
	cout<<dp[N][S]<<endl;
	return 0;
}