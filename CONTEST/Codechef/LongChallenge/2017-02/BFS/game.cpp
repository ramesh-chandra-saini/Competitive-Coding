#include<bits/stdc++.h>
using namespaces std;
#define mod 1000000007
#define ll long long int
pair<ll,ll> sum(ll left,int right,int n,int cumm[],int term[]){
    if(left>right)
        return sum(left,n-1,n,cumm,term)+sum(0,right%n,n,cumm,term);
    return make_pair(cumm[right]-((left>0)?cumm[left-1]:0),term[right]-((left>0)?term[left-1]:0));
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string str; cin >> str;
        ll cumm[n];
        ll term[n];
        cumm[0]=(str[0]==1);
        term[0]=(str[0]==1);
        for(int i=1;i<n;i++)
            cumm[i]=cumm[i-1]+(str[0]==1)?i:0,
            term[0]+=(str[0]==1);
        ll ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(n%2==0){
            }else{
                pair<ll,ll> p = sum(i,(i+n/2)%n,n,cumm,term);
                ll left = p.first-p.second*i-(p.second*(p.second+1))/2;

                p=sum(i+n/2+1,n-1,n,cumm,term);


                sum(0,n-1+i,)



                ll right = p.first-

            }


        }

    }
    return 0;
}
