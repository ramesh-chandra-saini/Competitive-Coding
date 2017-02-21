#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi 3.14159265358979323846
ld area(ll i,ld r,ld angle){
    ld areOfCircle = (angle*r*r)/(ld)2.0;
    ld s = (i+r+r)/(ld)2.0;
    ld areOfTriangle = sqrt(s*(s-i)*(s-r)*(s-r));
    cout<<"Circle : "<<areOfCircle<<" Triangle : "<<areOfTriangle<<endl;
    return areOfCircle - areOfTriangle;
}
int main(){
    ll t; cin >> t; while(t--){
        ld d; cin >> d;
        ld r = d/(ld)2.0;
        vector<ld> arr;arr.clear();
        for(ll i=1;i<=d-1;i++){
            a = i,b=r,c=r;
            ld cosTheta =(ld)(b*b+c*c-a*a)/(ld)(2.0*b*c);
            a= sqrt(d*d-i*i),b=r,c=r;
            ld cosTheta2 =(ld)(b*b+c*c-a*a)/(ld)(2.0*b*c);
            ld theta = acos(cosTheta);
            ld theta2 = acos(cosTheta2);
            ll rat = (ld)(r*r+r*r-i*i)/(ld)(2*r*r);
            ld Theta = acos(rat);
            ld Theta2 = (ld)180.00-Theta;
            ld B1 = area(i,r,Theta);cout<<Theta<<" "<<B1<<endl;
            ld B2 = area(sqrt(d*d-i*i),r,Theta2); cout<<Theta2<<" "<<B2<<endl;
            arr.push_back(B1+B2);
        }
        sort(arr.begin(),arr.end()); for(int i=0;i<arr.size();i++) cout<<arr[i]<<" "; cout<<endl;
        vector<ll> freq; freq.clear();
        for(vector<ld>::iterator i = arr.begin();i!=arr.end();){
            ld curr = *i,ct = 0;
            while(i!=arr.end() && curr==*i)
                ct++,i++;
            freq.push_back(ct);
        } for(int i=0;i<freq.size();i++) cout<<freq[i]<<" "; cout<<endl;
        ll N = freq.size();
        vector<ll> cumm(N+1,0);
        for(int i=1;i<N;i++)
            cumm[i]=cumm[i-1]+freq[i]; cumm[N]=cumm[N-1]+0;
        ll L = 0, E = 0, R = 0; for(int i=0;i<cumm.size();i++) cout<<cumm[i]<<" "; cout<<endl;
        for(int i=1;i<N;i++){
            L+=cumm[i-1];
            E+=cumm[i]-cumm[i-1];
            R+=cumm[N]-cumm[i+1];
        }
        cout<<L<<" "<<E<<" "<<R<<endl;

    }
    return 0;
}
