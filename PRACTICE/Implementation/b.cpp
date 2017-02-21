#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){

   if((x&1)==(y&1)){ //both even or both odd
      if((x&1)==0){ //both even
         return x<y;
      }else{ //both odd
        return x>y;
      }
   }
   if((x&1)==0) return(1);
   else   return(0);
}
int main(){
  int n;
  cin>>n;
  int i,arr[n];
  for(i=0;i<n;i++)
  cin>>arr[i];
  sort(arr,arr+n,cmp);
  for(i=0;i<n;i++)
  cout<<arr[i]<<" ";
}
