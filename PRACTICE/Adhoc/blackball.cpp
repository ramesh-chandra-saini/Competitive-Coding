#include<bits/stdc++.h>
using namespace std;
int main()
{
  int i,j,t,n,k,m;
  cin>>t;
  while(t--)
  {
    cin>>n>>k>>m;
    int arr1[n+1],arr2[n+1];
    for(i=0;i<n;i++)
    cin>>arr1[i];
    for(j=0;j<n;j++)
    cin>>arr2[j];
    int arr3[k+m+1];
    for(i=0;i<k;i++)
    cin>>arr3[i];
    for(;i<k+m;i++)
    cin>>arr3[i];
    for(i=0;i<n;i++)
    arr1[i]=arr1[i]-arr2[i];
    sort(arr1,arr1+n);
    sort(arr3,arr3+k+m);
    j=k+m-1;
    int ans=0;
    for(i=n-1;i>=0&&j>=0;)
    {
      if(arr3[j]>arr1[i])
      j--;
      else
     {
       ans+=arr1[i]-arr3[j];
       i--;
       j--;
      }
     }
     while(i>=0)
     ans+=arr1[i--];
     cout<<ans<<endl;
  }
  return(0);
}
