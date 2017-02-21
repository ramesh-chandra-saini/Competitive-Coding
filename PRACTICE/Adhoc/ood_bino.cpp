#include<bits/stdc++.h>
using namespace std;

int main(){


    int N;
    cin >> N;

    int i=0;
    int ans=0;

    for(int i=0;i<=N;i++){

        //cout << ( i & (N-i) ) <<endl;
        if( (i & (N - i ) ) == 0){

            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
