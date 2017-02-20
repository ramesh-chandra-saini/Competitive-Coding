#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int A,D,R,T,P,Q;

    cin >> T;

    while(T--){

        cin >> A >> D  >> R;

        P=A*R*(R-1)*(R-1)+D*R*(R-1);
        Q=(R-1)*(R-1)*(R-1);

        long long int F=__gcd(P,Q);

        P/=F; Q/=F;

        cout<<P<<" "<<Q<<endl;
    }
    return 0;
}
