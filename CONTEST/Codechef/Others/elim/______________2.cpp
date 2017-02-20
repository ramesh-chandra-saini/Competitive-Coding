#include<bits/stdc++.h>
using namespace std;
bool sortedArray(vector<int> & arr){
    vector<int> Xerox(arr);
    sort(Xerox.begin(),Xerox.end());
    return Xerox==arr;
}
int main(){
    int n ; cin >> n;
    vector<int> arr(n); for(int i=0;i<n;i++) cin >> arr[i];
    while(!sortedArray(arr)){
        for(int i=1;i<n;i++)
            if( arr[i]<arr[i-1])
                swap(arr[i],arr[i-1]),cout<<(i-1+1)<<" "<<(i+1)<<endl;
    }
    return 0;
}
