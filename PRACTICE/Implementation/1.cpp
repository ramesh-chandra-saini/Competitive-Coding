#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;while(t--){
        int n; cin >> n;
        long double total =0;
        for(int i=0;i<n;i++){
            long double t,p; cin >> t >> p;
            total+=t;
            total = total/p;
        }
        printf("%.9Lf\n",total);
    }

}
