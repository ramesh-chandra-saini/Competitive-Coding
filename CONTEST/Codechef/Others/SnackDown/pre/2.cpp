#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=0;i<n;i++)  cout<<(char) ('a'+(i%26)); cout<<endl;
    }
    return 0;
}
