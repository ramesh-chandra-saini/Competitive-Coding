#include<iostream>
#include<iomanip>
using namespace std;
void merge(long long int arr[],long long int low,long long int mid,long long int high)
{
     int temp[high+2],i=low,j=low,m=mid+1;
      while(j<=mid  && m<=high)
       {
		if(arr[j]<=arr[m]) 
		{
			temp[i++]=arr[j++];
		}		
		else temp[i++]=arr[m++];
       }
      if(j>mid)
	{	
    	   while(m<=high) temp[i++]=arr[m++];
	} 
	else 
        {
            while(j<=mid)  temp[i++]=arr[j++];
        }
	for(i=low;i<=high;i++) arr[i]=temp[i];
}
void part(long long int arr[],long long int low,long long int high)
{
   if(low<high)
   {
	  long long int mid=(low+high)/2;
	   part(arr,low,mid);
 	   part(arr,mid+1,high);
            merge(arr,low,mid,high);
   }
}

int main()
{
	long long int size;
	//cout<<"Enter the size of array"<<endl;
	cin>>size;
	long long int arr[size+1],temp2=size;
	//cout<<"Enter the elements of array"<<endl;
	for(long long int i=0;i<size;i++)
	{ arr[i]=temp2; temp2--;}
	part(arr,0,size-1);
	cout<<"Sorted Element "<<endl;
	for(long long int i=0;i<size;i++)
	cout<<arr[i]<<setw(10);
	 cout<<endl;
return 0;
}
