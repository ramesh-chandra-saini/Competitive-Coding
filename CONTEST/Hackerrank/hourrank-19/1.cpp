#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin >> N;

    long long ans = 0;
    long long arr[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];

    }
    for(int i=0;i<N;){
        int n = arr[i++];
        ++ans;
        while(n--){
            ++i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
