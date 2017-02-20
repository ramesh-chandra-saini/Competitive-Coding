#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int A[n],B[n];
        for(int i=0;i<n;i++)
            cin >> A[i];
        for(int i=0;i<n;i++)
            cin >> B[i];
        int prev=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(A[i]-prev>=B[i]) ans++;
            prev=A[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
