#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int arr1[60];
int knap(int arr[],int v,int n)
{
	int dp[v+1][n+1],i,j;
	for(i=0;i<=n;i++)
	dp[0][i]=0;
	for(j=1;j<=v;j++)
	dp[j][0]=0;
	for(i=1;i<=v;i++)
	for(j=1;j<=n;j++)
	{
		if(i>=arr[j-1])
		{
			dp[i][j]=max(dp[i][j-1],dp[i-arr[j-1]][j-1]+arr[j-1]);
		}
		else
		dp[i][j]=dp[i][j-1];
	}

    i=v;
    j=n;
    //cout<<"Backtraking\n";
    while(j>0)
    {
    	if(dp[i][j]-dp[i-arr[j-1]][j-1]==arr[j-1])
        {
        		arr1[j-1]=1;
        		//cout<<(j-1)<<" ";
        		i=i-arr[j-1];
        		j--;

		}
		else
		j=j-1;

	}
	//cout<<endl;
	return(dp[v][n]);
}
int main()
{
	int arr[60],x,arr2[60],i,j,t,n,k;
	cin>>t;
	while(t--)
	{
		int sum=0;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
		 cin>>arr[i];
		 sum+=arr[i];
		}
		int sum1=0;
		for(j=0;j<3;j++)
		{
			memset(arr1,0,sizeof(arr1));
			if(j==0)
			{
				x=0;
			   sum1+=knap(arr,k,n);
			    for(i=0;i<n;i++)
			   if(arr1[i]==0)
			   arr2[x++]=arr[i];
			   n=x;

				//cout<<sum1<<endl;
			   for(i=0;i<n;i++)
			   //cout<<arr2[i]<<" ";
			   //cout<<endl;
			}
			else if(j==1)
			{
				x=0;
				sum1+=knap(arr2,k,n);
			   for(i=0;i<n;i++)
			   if(arr1[i]==0)
			   arr[x++]=arr2[i];
			   n=x;

			   //cout<<sum1<<" "<<x<<" "<<endl;
			   for(i=0;i<n;i++)
			   //cout<<arr[i]<<" ";
			   //cout<<endl;
			}
			else
			{
				x=0;
				sum1+=knap(arr,k,n);
                //cout<<sum1<<endl;
			}
		}
        if(sum1==sum)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;



	}


	return(0);
}
