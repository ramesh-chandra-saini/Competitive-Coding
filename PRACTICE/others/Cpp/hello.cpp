#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,i,n,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int arr[n+1];
		for(i=0;i<n;i++)
		cin>>arr[i];
		int flag=0;
		long long int maxend=0,maxsofar=0,start=0,end1=0,maxlength=0,l=0,r=0;
		for(i=0;i<n;i++)
		{
		  maxend+=arr[i];
		   if(arr[i]>=maxend)
		   {
		   	maxend=arr[i];
		   	start=i;
		   }
		   if(maxsofar<maxend)
		   {
		   	maxsofar=maxend;
		   	end1=i;
		   	maxlength=end1-start;
		   }
		   else if(maxsofar==maxend)
		   {
		     long long int hell=i-start;
		     if(hell>=maxlength)
		     {
		        l=start;r=i;
		        flag=1;
		     }

		   }

		}
		if(maxsofar<=0)
		cout<<0<<" "<<0<<" "<<0<<endl;
		else if(!flag)
        cout<<start<<" "<<end1<<" "<<maxsofar<<endl;
        else
        cout<<l<<" "<<r<<" "<<maxsofar<<endl;
	}
	return(0);
}
