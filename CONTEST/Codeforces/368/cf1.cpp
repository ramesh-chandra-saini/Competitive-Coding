#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll l1,r1,l2,r2,k,start,end;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    start = max(l1,l2);
    end=min(r1,r2);
    ll duration = (end-start+1);
    if(start<=k && k<=end) duration--;
    (duration>0)? cout<<duration<<endl:cout<<"0"<<endl;
    return 0;
}
