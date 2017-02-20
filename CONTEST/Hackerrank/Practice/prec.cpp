#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,flag,n;cin >> t;
    while(t--){

        double ans=double(0),div=double(1),one=double(1),two=double(2);
        flag=1;
        cin >> n;
        for(int i=0;i<n;i++,flag*=-1,div+=two){
            ans+=flag*one/div;
        }
        printf("%.34lf\n",ans);
    }
    return 0;
}
