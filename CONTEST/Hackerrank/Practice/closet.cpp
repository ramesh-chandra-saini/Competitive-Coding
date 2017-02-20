#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;

    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin >> arr[i];


    sort(arr,arr+n);

    int diff=INT_MAX;

    for(int i=1;i<n;i++)
        diff=(diff>abs(arr[i]-arr[i-1]))?abs(arr[i]-arr[i-1]): diff;

    vector< pair < int , int > > ans; ans.clear();

    for(int i=1;i<n;i++){

        if(abs(arr[i]-arr[i-1])==diff)
        ans.push_back(make_pair(min(arr[i],arr[i-1]),max(arr[i],arr[i-1])));
    }

    sort(ans.begin(),ans.end());
    int size=ans.size();
    for(int i=0;i<size;i++)
        cout<<ans[i].first<<" "<<ans[i].second<<" "; cout<<endl;
    return 0;
}
