#include<bits/stdc++.h>
using namespace std;

int main(){


    int arr[]={7,1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    int low=0,high=n-1;

    int pivot=-1;
    while(low<high){

        if(arr[low]<=arr[high]){

            pivot =low; break;
        }
        int mid=(low+high)/2;

        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;

        if(arr[mid]<=arr[prev] && arr[mid]<=arr[high]){

            pivot =mid;
        }
        else if(arr[mid]<=arr[high]) mid=high-1;
        else low=mid+1;
    }
}
