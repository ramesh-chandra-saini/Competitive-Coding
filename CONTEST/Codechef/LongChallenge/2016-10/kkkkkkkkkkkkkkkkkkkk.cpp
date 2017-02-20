#include<bits/stdc++.h>
using namespace std;
#define ll long long
void binSearch(vector<ll>&B,ll low,ll high,ll key,ll &idx){
    if(low>high)    return;
    ll mid = (low+high)/2;
    if(B[mid]>=key) idx = mid,binSearch(B,low,mid-1,key,idx);
    else  binSearch(B,mid+1,high,key,idx);
}
ll getEnergy(vector<ll>&box,vector<ll>&arr,ll n,vector<ll>&freq,vector<ll>&B,ll N){
ll Energy=0LL;
   for(ll i=0;i<n;i++){
        ll idx = N-1;
        binSearch(B,0,N-1,box[i],idx);
        ll ct =freq[N-1]-freq[idx];
        //cout<<box[i]<<"["<<ct<<"]  ";
        Energy+=ct*arr[i];
    }  //cout<<endl;
         return Energy;
}
int main(){
    ll t;  scanf("%lld",&t);
    while(t--){
        ll n,m;scanf("%lld%lld",&n,&m);
        vector<ll> arr(n); for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);
        ll fans = 1LL<<62;
        sort(arr.begin(),arr.end());
        for(int c=1;c<=1+m%n;c++){
            vector<ll> box(n,0);
            ll M = m,i=0;
            for(ll i=0;i<n;i++){
                if(M<c){
                    ll ct = max(1LL,M/(n-i+1));
                    for(;i<n;i++){
                        if(M<ct){
                            box[i]=M;M=0; break;
                        }else{
                            box[i]=ct;
                            M-=ct;
                        }
                    }
                    box[n-1]+=M;M=0;
                    break;
                }else{
                    box[i]=c;
                    M-=c;
                }
            } box[n-1]+=M;M=0; //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            sort(box.begin(),box.end());
              map<ll,ll> my;
                 for(ll i=0;i<n;i++) my[box[i]]++;
                ll N = my.size(),p=0;
                vector<ll>B(N),freq(N);
                for(map<ll,ll>::iterator it = my.begin();it!=my.end();it++,p++)
                        B[p]=(it->first),freq[p]=(it->second);
                for(int i=1;i<N;i++)  freq[i]+=freq[i-1];
            for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
                fans = min(fans,getEnergy(box,arr,n,freq,B,N));
                ll val=box.back(); box.pop_back();
                box.insert(box.begin(),val);
            }
        }    printf("%lld\n",fans);

    }return 0;
}
