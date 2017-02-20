#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long long
ll get(ll A){
    ll a = sqrt(A) ;
    if(a*a<=A)
    	while(a+1<=A&&(a+1)*(a+1)<=A) ++a;
   	else
   		while(a-1>=0 && (a-1)*(a-1)>=A)	--a;
    return a;
}
int main(){
    ll t; cin >> t; while(t--){

        ll d,a; cin >> d;

        vector<ll> arr;arr.clear();
        for(ll i=1;i<d;i++){
            a=i;
            ll b=get(d*d-a*a);
            if(a*a+b*b==d*d){
                arr.push_back(a*b); //cout<<a<<" "<<b<<endl;
            }
        }
        sort(arr.begin(),arr.end()); //cout<<"A1+A2 ";for(int i=0;i<arr.size();i++) cout<<arr[i]<<" "; cout<<endl;
        vector<ll> freq; freq.clear();
        for(int i=0;i<arr.size();){
            ld curr = arr[i],ct = 0;
            while(i<arr.size() && curr==arr[i])
                ct++,i++;
            freq.push_back(ct);
        }  //cout<<"freq  "; for(int i=0;i<freq.size();i++) cout<<freq[i]<<" "; cout<<endl;
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
        cout<<L<<" "<<E<<" "<<R<<endl;
    }
    return 0;
}
