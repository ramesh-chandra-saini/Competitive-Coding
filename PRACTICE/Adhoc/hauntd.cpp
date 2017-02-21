#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,n,m,i,j;
cin>>t;
while(t--)
{
   cin>>n>>m;
   char arr[m];
   int flag=0;
   int top=INT_MAX;
   int bottom=INT_MIN;
   int left=INT_MAX;
   int right=INT_MIN;
   for(i=0;i<n;i++)
   {
      cin>>arr;
      for(j=0;j<m;j++)
      {
        if(arr[j]=='*')
        {
          flag=1;
          top=min(top,i);
          bottom=max(top,i);
          left=min(left,j);
          right=max(right,j);
        }
      }
   }
   if(flag)
   {
     int ans=max((bottom-top+1),(right-left+1));
     ans/=2;
     printf("%d\n",ans+1);
   }
   else
   printf("0\n");

}

return(0);
}

