#include<bits/stdc++.h>
using namespace std;
int main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];for(int i=0;i<n;i++) cin >> arr[i];
        bool failed=false;
        float total=0;
        bool excel=false;
        for(int i=0;i<n;i++){
            if(arr[i]<=2) failed=true;
            if(arr[i]>=5) excel=true;
            total+=arr[i];
        } float avg=total/(float)n;
        if(!failed && excel && avg>=4.0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
