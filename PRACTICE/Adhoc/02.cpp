#include<bits/stdc++.h>
using namespace std;

int main(){

	int T;
	scanf("%d",&T);

	while(T--){

		int N;
		scanf("%d",&N);

		int arr[N];

		for(int i=0;i<N;i++)
			scanf("%d",&arr[i]);

		//Check for Non-decreasing property
		int sum=0;
		int gcd=arr[0];

        if(arr[0]==1){
            arr[0]=2;sum=1;gcd=arr[0];
        }

		for(int i=1;i<N;i++){

			if(arr[i]<arr[i-1]){

				sum+=arr[i-1]-arr[i];
				arr[i]=arr[i-1];
			}
			gcd=__gcd(gcd,arr[i]);
		}

		if(gcd!=1) printf("%d\n",sum);
		else {

            int check1=0;

			for(int i=0;i<N;i++)
				check1+=arr[i]%2;

            bool visit[N];
            memset(visit,false,sizeof(visit));

            for(int j=0;j<N;j++){

                int check2=0;

                if(visit[j]){

                for(int i=0;i<N;i++){
                    check2+=(arr[i]%arr[j]==0) ? 0: (arr[j]-(arr[i]%arr[j]) );

                    if(arr[i]%arr[j]==0) visit[i]=true;

                    }
                }

                check1=min(check1,check2);
            }

			sum+=check1;

			printf("%d\n",sum);
		}
        /*
		for(int i=0;i<N;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		*/
	}
	return 0;
}
