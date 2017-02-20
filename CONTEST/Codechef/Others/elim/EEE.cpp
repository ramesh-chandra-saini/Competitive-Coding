// C program to demonstrate working of extended
// Euclidean Algorithm
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

// Driver Program
int main()
{

    ll T; cin >> T;
    while(T--){

    ll N, Sum; cin >> N >> Sum;
   ll a=N;
    ll b=(N*(N-1))/2LL;
    ll c = Sum;
    ll x,y;
     ll g = gcdExtended(a, b, &x, &y);
     ll n =x;
     ll m =y;

     ll n_b = n/__gcd(n,b);b/=__gcd(n,b);
     ll c_b=c/__gcd(c,b);b/=__gcd(b,c);

    ll m_a = m/__gcd(m,a);a/=__gcd(m,a);
     ll c_a=c/__gcd(c,a);a/=__gcd(a,c);
 if(-n_b*c_b<m_a*c_a && b==1LL && a ==1LL) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;


/*
    ll x, y,a,b;
    cin >> a >> b;
    cout<<__gcd(56,72)<<endl;
    ll g = gcdExtended(a, b, &x, &y);
    prllf("gcd(%d, %d) = %d, x = %d, y = %d",
           a, b, g, x, y);
*/
    } return 0;
}
