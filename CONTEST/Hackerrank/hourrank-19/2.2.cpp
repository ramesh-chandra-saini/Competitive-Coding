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
    map<long long,long long> fr;
    fr[0]=1;
    for(int i=N;i>=2;i--){
        ++fr[R[i]];
    }

    long long ans = 0;
    for(int i=2;i<=N+1;i++){
        long long leftXor  = L[i-2];
        ans += fr[leftXor];
        --fr[R[i]];
    }
    cout<<ans<<endl;
    return 0;
}
