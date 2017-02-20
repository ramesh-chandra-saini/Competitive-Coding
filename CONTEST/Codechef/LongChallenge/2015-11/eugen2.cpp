/*
    AUTHOR : RAMESH CHANDRA
*/
#include<bits/stdc++.h>
using namespace std;

long long int F(long long int N){

    if(N<10) return N;

    long long int __N=0;
    for(;N > 0 ;N/=10)
        __N+=N%10;
    return F(__N);
}

int main(){

    long long int T;
    cin >> T;

    long long int A,D,L,R;
    while(T--){

        cin >> A >> D >> L >> R;

        long long int arr[9];

        long long int BLOCK=0;

        for(int i=0;i<9;i++){

            arr[i]=F(A+i*D);
            BLOCK+=arr[i];
        }
        //cout<<BLOCK<<endl;
        long long int Right=(R/9)*BLOCK;
        for(long long int i=(R/9)*9+1,j=0;i<=R;i++,j++)
            Right+=arr[j];

        L--;
        long long int Left=(L/9)*BLOCK;
        for(long long int i=(L/9)*9+1,j=0;i<=L;i++,j++)
            Left+=arr[j];
        cout<<Right-Left<<endl;
    }
    return 0;
}
