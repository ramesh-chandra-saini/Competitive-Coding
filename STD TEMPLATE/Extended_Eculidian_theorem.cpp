#include<bits/stdc++.h>
using namespace std;

int d, x, y;
void extendedEuclid(int A, int B) {

    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
         cout<<"("<< x<<","<<y<<") :: ";
      cout<<endl;
        extendedEuclid(B, A%B);

         cout<<"("<< x<<","<<y<<") ==> ";
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
         cout<<"("<< x<<","<<y<<")";  cout<<endl;

    }

}

int main( ) {
extendedEuclid(16, 10);
cout << "The GCD of 16 and 10 is " << d << endl;
cout << "Coefficient x and y are: "<< x <<  "and  "<< y << endl;
return 0;
}
