/******************MAX HEAPSORT**************/
#include<bits/stdc++.h>
using namespace std;
inline void swap(int &a,int &b){
  int c=a; a=b; b=c; return ;

}
void heapify(int arr[],int size)
{
    for(int i=0;i<=size;i++)
    {
        int child=i;
        while(child)
        {
            int root=(child-1)/2;
             if(arr[root]<arr[child]){
                swap(arr[root],arr[child]);
                }
            child=root;
        }
    }
    return ;
}
int main(){
    int size;
    cout<<"Enter the size of data"<<endl; cin>>size;// cout<<"Size  :  "<<size<<endl;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
        heapify(arr,i);
        }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
        } cout<<endl;
      for(int j=0;j<size-1;j++){
        swap(arr[0],arr[size-1-j]);
        //cout<<"SWAPPED   :  "<<endl; for(int i=0;i<size;i++){cout<<arr[i]<<"\t";} cout<<endl;
        heapify(arr,size-1-j-1);
           //  cout<<"HEAPIFY  : "<<endl; for(int i=0;i<size;i++){cout<<arr[i]<<"\t";} cout<<endl<<endl;
      }
      cout<<"SORTED ARRAY"<<endl;
       for(int i=0;i<size;i++){
            cout<<arr[i]<<"\t";
        } cout<<endl;
return 0;
}
