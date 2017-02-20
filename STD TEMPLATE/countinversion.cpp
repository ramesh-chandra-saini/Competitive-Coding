#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll  pass(ll arr[],ll size)
{
ll count2=0 ,count=0,total=0;

  for(ll i=0;i<size;i++)
  {
    if(arr[i]>=2)  count++;
    if(arr[i]==1) total+=count;

     if(arr[i]==3) count2++;
      else if(arr[i]==2) total+=count2;

  }
   return total;
}
int main()
{
ll size; cin>>size;
  ll arr[size];

  for(ll i=0;i<size;i++ ) cin>>arr[i];
   cout<<pass(arr,size)<<endl;
return 0;
}
