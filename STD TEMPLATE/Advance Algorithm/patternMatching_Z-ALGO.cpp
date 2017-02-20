/*this is what i have learnt after spending half of day.*
*..hope to improve further*
*/

#include<bits/stdc++.h>
using namespace std;
long long int compute_Z(char str[]){


	long long int n=strlen(str);
	vector<long long int> Z(n,0);


	long long int L=0,R=0;
	long long int sum=0;

	for(long long int i=1;i<n;i++){

		if(i>R){

			//not computed yet
			L=R=i;

			while(R<n && str[R-L]==str[R]) R++;

			R--;//this step taken to avoid such
			//condition R==n or str[L-R]!=str[R]....hope  got it


			Z[i]=R-L+1; // calculate matching character matching
			//eg. start 3 8 total number of character=8-3+1, simple one 2-2 TN=2-2+1;
		}
		else{

			//we know we are in already computed segment
			//there is two condition firt one is simple

		    long long int k=i-L;
			//because we know here str[0..k] str[l..r]
		    if(Z[k]<R-i+1){
		    // this show we have computed value of required Zi and
		    // total number of character in range in [i..R] are less than to Z[k]..
				Z[i]=Z[k];
			}
			else{
			    //little confusing part...
			    //don't worry  will see next time to better under understanding
				//now time to update starting point of starting index of substring

			    L=i; //think why....??
				while(R<n && str[R-L]==str[R]) R++;


				R--;//this step taken to avoid such condition
				// R==n or str[L-R]!=str[R]....hope  got it

				Z[i]=R-L+1; // calculate matching character matching
				//start 3 8 total number of character=8-3+1, simple one 2-2 TN=2-2+1;
			}
		}

		sum+=Z[i];
	}

	return sum;
}
int main(){


	long long int test;
	scanf("%lld",&test);

	char str[100001];
	while(test--){

		scanf("%s",str);
		printf("%lld\n",(compute_Z(str)+strlen(str)));
	}

	return 0;
}