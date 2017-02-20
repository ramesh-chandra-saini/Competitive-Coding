#include<bits/stdc++.h>
using namespace std;
bool BinSearch(ll arr[],ll start,ll end,ll key)
{
if(start>=end)  return false ;
int mid=(start+end)/2;
if(arr[mid]==key) return true;
else if(arr[mid]>key) BinSearch(arr,start,mid-1,key);
else BinSearch(arr,mid+1,end,key);
}
int main(){
int size; cout<<"Enter the size : "<<endl; cin>>size;
    int arr[size]; cout<<"Enter data(sorted)"<<endl;
    for(int i=0;i<size;i++) cin>>arr[i];
    cout<<"Enter the key element :"<<endl; int key; cin>>key;
   if(BinSearch(arr,0,size-1,key)) cout<<"Key element is present "<<endl;
    else cout<<"Key element is not present in given data"<<endl;
}

