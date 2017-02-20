
#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950288419716939937
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double r1,h1,r2,h2;
		double c1=0,c2=0;
		cin>>r1>>h1>>r2>>h2;
		c1=(pi*r1*r1*h1)*(1.0/3.0)+(2.0/3.0)*pi*r1*r1*r1;
		c2=(pi*r2*r2*h2);
		printf("%.9f %.9f\n",c1,c2);
	}
	return(0);
}
