#include<bits/stdc++.h>
using namespace std;
int main(){

    int n; cin >> n;
    int ct2=0,ct5=0;
    for(int i=1,temp;i<=n;i++){
        temp=i;      while(temp%2==0) ct2++,temp/=2;
        temp=i;      while(temp%5==0) ct5++,temp/=5;
    }
    cout<<min(ct2,ct5)<<endl;

    int arr[n]; for(int i=0;i<n;i++) arr[i]=i; for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
    reverse(arr,arr+n); for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;


}
