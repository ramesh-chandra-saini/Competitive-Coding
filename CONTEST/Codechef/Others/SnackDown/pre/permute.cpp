// C program to print all permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void permute(vector<ll> &a, ll l, ll r,set<vector<ll> > &eset){
   ll i;
   if (l == r){
    //for(ll j=0;j<a.size();j++) cout<<a[j]; cout<<endl;
    eset.insert(a);}
   else{
       for (i = l; i <= r; i++){
           swap(a[l], a[i]);
          permute(a, l+1, r,eset);
          swap(a[l], a[i]);
       }
   }
}
set<vector<ll> > allPermute(vector<ll> &a){
    set<vector<ll> > eset;
    permute(a, 0LL, a.size()-1,eset);
    return eset;
}
int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
     set<vector<ll> > eset=allPermute(a);
    for(set<vector<ll> >:: iterator it=eset.begin();it!=eset.end();++it){
        vector<ll> vec = *it;
        for(int i=0;i<vec.size();i++) cout<<vec[i]<<" "; cout<<endl;
    }
    cout<<eset.size()<<endl;
    return 0;
}
