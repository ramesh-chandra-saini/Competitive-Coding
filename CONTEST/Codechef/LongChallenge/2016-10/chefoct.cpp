#include<bits/stdc++.h>
#define PI 3.14159265358979323846
#define ld long double

using namespace std;

int main(){

     int t;
     cin>>t;
     while(t--){

      long double s,v,ans;
      cin>>s>>v;

      long double h=s/((long double)2*(long double)sqrt(3));
      long double r=s/2;

      long double x=(long double)2*PI*sqrt(h*h+r*r);



      //ans=(PI*s)/(4*v);
      ans=(PI*sqrt((long double)3)*s)/((long double)8*v)*(long double)4;


     printf("%.12Lf\n",ans);
     }
}
