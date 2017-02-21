#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,q; cin >> n >> q;
    vector<vector<int> > arr(n,vector<int>());
    int lastAns = 0;
    while(q--){
        int type; cin >> type;
        if(type==1){
            int x,y; cin >> x >> y;
            int id = ((x xor lastAns)%n);
            arr[id].push_back(y);
        }else {
           int x,y; cin >> x >> y;
            int id = ((x xor lastAns)%n);
            int i = y%(arr[id].size());
            lastAns = arr[id][i];
            cout<<lastAns<<endl;
        }
    }
    return 0;
}
