#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi 3.14159265358979323846
ld area(ll i,ld r,ld angle){
    ld areOfCircle = (angle*r*r)/(ld)2.0;
    ld s = (i+r+r)/(ld)2.0;
    ld areOfTriangle = sqrt(s*(s-i)*(s-r)*(s-r));
    return areOfCircle - areOfTriangle;
}







int main(){
    ll t; cin >> t; while(t--){
        ld d,a,b,c; cin >> d;
        ld r = d/(ld)2.0;
        vector<ld> arr;arr.clear();
        ld areaOfCircle = (pi*r*r)/(ld)2.00;
        for(ll i=1;i<=d-1;i++){
            a=i;
            b=sqrt(d*d-i*i);
            if(b-(ld)((ll)b)==0){
                ld Area = (a*b)/(ld)2.00;cout<<a<<" "<<b<<" "<<areaOfCircle<<" "<<Area<<" "<<areaOfCircle-Area<<endl;
                arr.push_back(areaOfCircle-Area);
            }
        }
        sort(arr.begin(),arr.end()); cout<<"A1+A2 ";for(int i=0;i<arr.size();i++) cout<<arr[i]<<" "; cout<<endl;
        vector<ll> freq; freq.clear();
        for(int i=0;i<arr.size();){
            ld curr = i,ct = 0;
            while(i<arr.size() && curr==arr[i])
                ct++,i++;
            freq.push_back(ct);
        }  cout<<"freq  "; for(int i=0;i<freq.size();i++) cout<<freq[i]<<" "; cout<<endl;
        ll N = freq.size();
        freq.insert(freq.begin(),0); freq.insert(freq.end(),0);
        for(int i=1;i<=N+1;i++)
            freq[i]+=freq[i-1];
        ll L = 0, E = 0, R = 0; //cout<<"comm ";for(int i=0;i<freq.size();i++) cout<<freq[i]<<" "; cout<<endl;
        for(int i=1;i<=N;i++){
            L+=freq[i-1]*freq[i];
            E+=(freq[i]-freq[i-1])*freq[i];
            R+=(freq[N]-freq[i+1])*freq[i];
        }
        cout<<E<<" "<<E<<" "<<R<<endl;
    }
    return 0;
}
