#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;

    cin >> t;

    while(t--){


        int n;
        cin >> n;

        long long int K,_K;
        if(n<=4) cout<<"NO"<<endl;
        else{

            if(n%2==0)  K=4*n-4;
            else K=2*n-1;

            _K=sqrt(K);
            if(_K * _K == K ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
