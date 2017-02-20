#include<bits/stdc++.h>
using namespace std;

int main(){


    long long int N;

    cin >> N;

    long long int arr[N];

    for(int i=0;i<N;i++){

        cin >> arr[i];
    }

    sort(a,a+N);

    long long ans=arr[0]*arr[1]+arr[N-1]-arr[2];
    long long int mx;

    mx=arr[1]*arr[2]+arr[N-1]-arr[0];
    ans=max(mx,ans);

    mx=arr[N-1]*arr[N-2]+arr[N-3]-arr[0];
    ans=max(ans,mx);

    mx=arr[N-2]*arr[N-3]+arr[N-1]-arr[0];

    ans=mx(ans,mx);

    cout<<ans<<endl;
}
