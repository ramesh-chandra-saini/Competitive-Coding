#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;

    while(t--){

        int n; cin >> n;
        int arr[n];

        for(int i=0;i<n;i++)
                cin >> arr[i];

        sort(arr,arr+n);
        long long int ans=0,k;
        for(int i=0;i<n;){

            int prev=arr[i];k=0;
            while(i<n && prev==arr[i]){k++; i++; }
            ans+=k*(k-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
