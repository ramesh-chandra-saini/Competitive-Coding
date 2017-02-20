#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,p; cin >> n >> p;
    int arr[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    set<int> h;
    while(h.size()<p-1){
        int k=1+rand()%(n-1);
        h.insert(k);
    }
    set<int > v;
    while(v.size()<p-1){
        int k=1+rand()%(n-1);
        v.insert(k);
    }
    for(set<int>::iterator it=h.begin();it!=h.end();++it)
        cout<<*it<<" ";cout<<endl;
    for(set<int>::iterator it=v.begin();it!=v.end();++it)
        cout<<*it<<" ";cout<<endl;
    return 0;
}
