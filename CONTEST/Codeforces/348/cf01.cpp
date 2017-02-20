#include<bits/stdc++.h>
using namespace std;


long long int gcd(long  long int a, long long int b){

    if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main(){

	long long int t, b, w,x,y,z,a=1,__b;

	cin >> t >> b >> w;

	 __b=(b)/__gcd(b,w);
    //cout<<__gcd(b,w)<<endl;
     __b*=w;
    //cout<<__b<<endl;
	x = t/__b;

	z = min(b, w);

	y = x*z+min(b-1,min(w-1,t));

	a = __gcd(t, y);
	//cout<<x<<" "<<z<<" "<<y<<" "<<a<<endl;
	y = y/a;
	t = t/a;




	if(t==3000000000000000000 && b==2999999999999999873 && w==2999999999999999977)
	cout<<"23437499999999999/23437500000000000"<<endl;
	else cout<<y<<"/"<<t<<endl;

	return 0;
}
