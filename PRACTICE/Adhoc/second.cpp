#include<bits/stdc++.h>
using namespace std;
main()
{
int t,a,b;
 cin>>t;
 while(t--)
 {
    int i,j;
    cin>>a>>b;
    int arr[b+1];
    memset(arr,0,sizeof(arr));
    for(i=2;i*i<=b;i++)
    {
       if(arr[i]==0)
       {
          for(j=i*2;j<=b;j=j+i)
          arr[j]=1;
       }
    }
    int ct=0;
    for(i=a;i<=b;i++)
    if(arr[i]==0)
    ct++;
    cout<<ct<<endl;
 }
}
