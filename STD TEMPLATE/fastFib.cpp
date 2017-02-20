#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int c,d,k;
long long int Fn(long long int N,long long int A,long long int B)
{
    //cout<<++i<<endl;
    if(N==1) return (A);
    else if(N==2) return (B);
    else if(N==3) return (A+B);
    else if(N%2)
    {
      k=N/2;
      c=Fn((k+1),A,B); d=Fn(k,A,B);
      return (c*c+d*d);
   //      return (Fn((N/2+1),A,B)*Fn((N/2+1),A,B)+Fn((N/2),A,B)*Fn((N/2),A,B));

    }
    else{
      k=N/2;
     c=Fn((k+1),A,B); d=Fn(k,A,B);
     return (d*(2*c-d));
   //     return (Fn((N/2),A,B)*( 2*Fn((N/2+1),A,B)-Fn((N/2),A,B) ));
   }
}
int main()
{
    long long int N,A,B,T;

    cin>>T;

    while(T--){

        cin>>A>>B>>N;
        cout<<Fn(N,A,B)<<endl;
    }
    return 0;
}
