#include<bits/stdc++.h>
using namespace std;
int main(){

    long long N;
    cin >> N;

    vector<long long > pile(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> pile[i];
    }
    vector<long long> L = pile;
    for(int i=2;i<=N;i++){
        L[i] = (L[i-1] ^ L[i]);
    }
    vector<long long> R = pile;
    for(int i=N-1;i>=1;i--){
        R[i] = (R[i+1] ^ R[i]);
    }
    R.push_back(0); //handle some corner case
    long long ans = 0;
    for(int b=1;b<=N;b++){
        for(int e=b;e<=N;e++){
            ans += (L[b-1] ^ R[e+1])==0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
