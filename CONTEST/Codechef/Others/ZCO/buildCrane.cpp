#include<bits/stdc++.h>
using namespace std;
bool craneHasItem=false;
int cranePosition=0;
void moveLeft(int arr[],int n){
    if(cranePosition==0) return;
    cranePosition--; return;
}
void moveRight(int arr[],int n){
    if(cranePosition == n-1 ) return;
    cranePosition++; return;
}
void pickUpBox(int arr[]){
    if(arr[cranePosition] == 0 || craneHasItem == true) return;
    craneHasItem =true; arr[cranePosition]--; return;
}
void dropBox(int arr[],int h){
    if(craneHasItem == false || arr[cranePosition] == h) return;
    craneHasItem =false; arr[cranePosition]++;return;
}
int main(){

    int n,h;
    cin >> n >> h;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int q; cin>>q;
    while(q){

        switch(q){
        case 1: moveLeft(arr,n);break;
        case 2: moveRight(arr,n);         break;
        case 3: pickUpBox(arr);        break;
        case 4 : dropBox(arr,h);        break;
        default:break;
        }
        cin >>q;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" "; cout<<endl;
    return 0;
}
