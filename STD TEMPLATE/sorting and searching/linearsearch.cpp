#include<bits/stdc++.h>
using namespace std;
int main(){
    int size; cout<<"Enter the size of data"<<endl; cin>>size;
    int arr[size],i;
    cout<<"Enter data "<<endl;
    for(i=0;i<size;i++) cin>>arr[i];
    int key; cout<<"Enter the key element "<<endl; cin>>key;
    for(i=0;i<size;i++)
        if(arr[i]==key) break;
    if(i<size){
        cout<<"Key element at "<<i+1<<"index (1-based index )"<<endl<<endl;}
    else
        cout<<"Not present key element"<<endl<<endl;
return 0;
}
