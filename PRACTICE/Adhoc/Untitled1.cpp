#include<bits/stdc++.h>
using namespace std;
main()
{
  int arr[200][300];
  int i,j;
  arr[0][0]=1;
  arr[1][0]=1;
  arr[1][1]=1;
  for(i=2;i<=150;i++)
  {
     arr[i][0]=1;
     for(j=1;j<i;j++)
     arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
     arr[i][i]=1;
  }
  int count=0;
  for(i=1;i<=150;i++)
  {
     count=0;
     for(j=0;j<=i+1;j++)
     if(arr[i][j]%2!=0)
     count++;
     cout<<i<<":"<<count<<endl;
  }
}
