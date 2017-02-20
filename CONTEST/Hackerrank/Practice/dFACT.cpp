#include <bits/stdc++.h>
using namespace std;
bool __success(long long int arr[],long long int N,long long int Bot_Energy){
    /*
    If hk+1>botEnergy, then he will lose hk+1−botEnergy units of energy.
    Otherwise, he will gain botEnergy−hk+1 units of energy
    */
    for(long long int i=0;i<N;i++){
         Bot_Energy+=(Bot_Energy-arr[i]);
        if(Bot_Energy<0) return false;
    }
    return true;
}
void __bin_search(long long int arr[],long long int N,long long int low,long long int high,long long int &ans){

    if(low>high) return;
    long long int mid=low+(high-low)/2; //cout<<mid<<" ";

    if(__success(arr,N,mid)){

        ans=mid;
        __bin_search(arr,N,low,mid-1,ans);
    }
    else __bin_search(arr,N,mid+1,high,ans);

}
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long int output to STDOUT */

    long long int N;
    cin >> N ;
    long long int __ans=INT_MIN;
    long long int arr[N];

    for(long long int i=0;i<N;i++){
            cin >> arr[i]; __ans=max(__ans,arr[i]);}
    long long int ans=__ans;
    __bin_search(arr,N,1,__ans,ans);
    cout<<ans<<endl;
    return 0;
}
