#include<bits/stdc++.h>
using namespace std;

int main(){

    int T,N;
    cin >> T ;

    while(T--){

        cin >> N ;

        /***mike ans **/
        bool mike=false;
        if(N%2) mike=true;

        /***real prob ans***/
        bool real = true;

        /**special case**/
        if(N == 1 ) real=false;

        for(int i=2;i*i<=N; i++)
            if( N %i ==0)
                real=false;
        //cout << mike << " " << real << endl;
        if(mike==real)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
