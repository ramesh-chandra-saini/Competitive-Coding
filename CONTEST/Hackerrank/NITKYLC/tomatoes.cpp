#include<bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;

    while(T--){

        int N,X;
        cin >> N >> X;

        int arr[N];

        for(int i=0;i<N;i++)
            cin >> arr[i];

        sort(arr,arr+N);
        int A=0,B=0,C=0;

        for(int i=N-1;i>=0;i--){

            if(A<=B && A<=C)
                A+=arr[i];
            else if(B<=A && B<=C)
                B+=arr[i];
            else
                C+=arr[i];
        }
         if(max(A,max(B,C))<=X) cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
    }
    return 0;
}
