#include<bits/stdc++.h>
using namespace std;

void printUtility(int [],int [],int ,int,int ,int);
int printCombination(int arr[],int n,int r){

    int data[r];

    printUtility(arr,data,0,n-1,0,r);
}
void printUtility(int arr[],int data[],int start,int end,int index ,int r){

    if(index==r){

        for(int i=0;i<r;i++) cout<<data[i]<<" "; cout<<endl;
    }
    else{


        for(int k=start;k<=end && end-k+1>=r-index;k++){

            data[index]=arr[k];
            printUtility(arr,data,k+1,end,index+1,r);
        }
    }

}
int main(){


    int arr[]={1,2,3,4,5,6,7};
    int r=3;
    int n=sizeof(arr)/sizeof(int);
    printCombination(arr,n,r);
    return 0;
}
