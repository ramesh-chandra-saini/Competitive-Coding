#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
	long long int arr[100009][2];
	arr[1][0]=0;
	arr[1][1]=1;
	arr[2][0]=2;
	arr[2][1]=1;
	arr[3][0]=3;
	arr[3][1]=2;
	for(long long int i=4;i<=100008;i++)
	{
		arr[i][0]=(arr[i-1][0]+arr[i-2][0]+arr[i-3][0])%M;
		arr[i][1]=(arr[i-1][1]+arr[i-2][1]+arr[i-3][1])%M;
	}
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int num;
		cin>>num;

		/*if(num==2)
		cout<<2<<" "<<1<<endl;
		else if(num==3)
		cout<<3<<" "<<2<<endl;
		else if(num==4)
		cout<<5<<" "<<4<<endl;
		else if(num==5)
		cout<<10<<" "<<7<<endl;
		else if(num==6)
		cout<<18<<" "<<13<<endl;
		else*/
		cout<<arr[num][0]<<" "<<arr[num][1]<<endl;
	}
	return(0);
}
