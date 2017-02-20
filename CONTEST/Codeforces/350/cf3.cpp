#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int s,x;
        cin >> s >> x;
    long long int ans=0;
    for(long long int a=0;a<=s;a++){
        for(long long int b=0;b<=s;b++){

            if( ((a+b)==s) && ( (a^b)==x) ){
                cout<<a<<"  "<<b<<"  "<<(a+b)<<"  "<<(a^b)<<endl;
                ans++;
            }
        }
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
