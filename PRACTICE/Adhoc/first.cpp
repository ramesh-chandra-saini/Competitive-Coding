#include<bits/stdc++.h>
using namespace std;
main()
{
int T,N,i,j;
cin>>T;
while(T--)
{
  cin>>N;
  int arr[N+1];
  for(i=0;i<N;i++)
  cin>>arr[i];
  sort(arr,arr+N);
  i=0;j=N-1;
  int k=1;
  while(i<=j)
  {
     if(k%2==0)
     {
        cout<<arr[i]<<" ";
        i++;
        k++;
     }
     else{
        cout<<arr[j]<<" ";
        j--;
        k++;
     }
  }
  cout<<endl;
}
}
