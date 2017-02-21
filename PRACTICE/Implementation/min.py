#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >>n;
    vector<int> arr(n); for (int i=0;i<n;i++) cin >> arr[i];
    vector<int> cp(arr);
    sort(cp.begin(),cp.end());
    int ct=1;
    for(int i=0;i<n;i++)
        ct+=cp[i]!=arr[i]
    print ct/2
    return 0;
}

