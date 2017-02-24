#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int N; cin >> N;
    string a,b; cin >> a >> b;
    vector<int> A,B;
    for(int i=0;i<a.length();i++)
        A.push_back(a[i]-'0');
    for(int i=0;i<b.length();i++)
        B.push_back(b[i]-'0');

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ans = 0;
    for(int i=0;i<N;i++){
        vector<int>::iterator it = lower_bound(B.begin(),B.end(),A[i]);
        if(it==B.end())
            ++ans,B.erase(B.begin());
        else
            B.erase(it);
    }
    cout<<ans<<endl;
    B.clear(),ans=0;
    for(int i=0;i<b.length();i++)
        B.push_back(b[i]-'0');
    sort(B.begin(),B.end());
    for(int i=0;i<N;i++){
        vector<int>::iterator it = upper_bound(B.begin(),B.end(),A[i]);

        if(it==B.end())
            B.pop_back();
        else
            ++ans,B.erase(it);
    }
    cout<<ans<<endl;
    return 0;
}
