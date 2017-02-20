#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int a,b,c,d,n; cin >> n >> a >> b >> c >> d;
    long long int x=n-max((d+a)-(b+a+1),1);
        x=min(x, n-max((b+c)-(b+a+1),1));
        x=min(x, n-max((c+d)-(a+b+1),1));
        x=max(x,0);
    long long int ans = (long long int)x * (long long int)n;
        cout<<ans<<endl;
    return 0;
}
