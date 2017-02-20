#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265
bool __EQUAL(double A,double B){
    if(abs(A-B)<0.000001) return true;
    return false;
}

int main(){

    int Id;
    cin >> Id;
    int t;
    cin >> t;

    while(t--){

        double x1,y1,x2,y2,x3,y3;
        cin >> x1>>y1>>x2>>y2>>x3>>y3;
        double A,B,C;
        A=sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
        B=sqrt( (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2) );
        C=sqrt( (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3) ) ;
        double _A,_B,_C;

        _A=acos( (A*A+B*B-C*C)/(2*A*B));
        _B=acos( (B*B+C*C-A*A)/(2*B*C));
        _C=acos( (A*A+C*C-B*B)/(2*C*A));
        double  val = 180.0 / PI;
        _A*=val;
        _B*=val;
        _C*=val;

        if(__EQUAL(A,B) || __EQUAL(A,C) || __EQUAL(B,C))
            cout<<"Isosceles ";
        else cout<<"Scalene ";

        if(Id==2){
            if( __EQUAL( _A ,90) || __EQUAL (_B ,90) || __EQUAL(_C, 90))
                cout<<"right ";
            else if(_A>90 || _B>90 || _C>90)
                cout<<"obtuse ";
            else cout<<"acute ";
        }
        cout<<"triangle"<<endl;
    }
    return 0;
}
