#include<bits/stdc++.h>
using namespace std;

int main(){


    int T,N;

    cin >> T ;

    while(T--){

        cin >> N ;

        int arr[10];
        memset(arr,0,sizeof(arr));
        for(;N>0;N/=10)
            arr[N%10]++;
    }

    return 0;
}
