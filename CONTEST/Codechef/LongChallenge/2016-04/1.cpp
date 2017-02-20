#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,n; cin >> t;
    while(t--){
        string s; cin >>n >> s;int R=0,G=0,B=0;
        for(int i=0;i<n;i++)
            (s.at(i)=='R') ? R++ : (s.at(i)=='G') ? G++ : B++;
        cout<<min(R+B,min(R+G,G+B))<<endl;
    }

    return 0;
}
