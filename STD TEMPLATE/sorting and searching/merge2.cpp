/******************************MERGE SORT IN NEW WAY IMPLEMENTATION****************/
/*******************************JUST CHECK IT OUT *******************************/
#include<iostream>
using namespace std;
int size;
void merge(int arr[],int low,int mid,int high)
{
   int l[mid+1],u,r[high+1],i=low,j=mid+1,k=low;
    for(u=low;u<=mid;u++) l[u]=arr[u];
    for(u=mid+1;u<=high;u++) r[u]=arr[u];
   while(i<=mid  && j<=high)
  {
	if(l[i]<=r[j]) {  arr[k]=l[i]; i++;}
	else {arr[k]=r[j]; j++;}
 	k++;
  }
  if(i>mid)
  {
     while(j<=high){arr[k]=r[j]; j++; k++;}
  }
  else
  {
     while(i<=mid) {arr[k]=l[i]; i++; k++;}
  }
  for(i=0;i<size;i++) cout<<arr[i]<<"\t";cout<<endl;
}
void part(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		part(arr,low,mid);
		part(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main()
{
	cin>>size;
	int arr[size],i;
	for(i=0;i<size;i++) cin>>arr[i];
	//for(i=0;i<size;i++) cout<<arr[i]<<"\t";cout<<endl;
	
	part(arr,0,size-1);
	//for(i=0;i<size;i++) cout<<arr[i]<<"\t";cout<<endl;
	return 0;
}