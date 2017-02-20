#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll M;
ll getEnergy(vector<ll>&box,vector<ll>&arr,ll n,ll Energy=0LL){
   vector<ll>freq(M+1,0LL);
   for(ll i=0;i<n;i++) freq[box[i]]++;
   for(int i=1;i<=M;i++)
        freq[i]+=freq[i-1];
    //for(int i=0;i<n;i++) cout<<box[i]<<" ";cout<<endl;
    for(ll i=0;i<n;i++){
        ll ct =freq[M]-freq[box[i]];
        //cout<<box[i]<<" "<<ct<<endl;
        Energy+=ct*arr[i];
    }
//    for(int i=0;i<n;i++) cout<<box[i]<<" "; cout<<" --> "<<Energy<<endl;
     return Energy;
}
ll ans;
vector<ll> see;
void fun(vector<ll>box,int i,int m,int n,vector<ll>&arr){
    if(m==0||i==n-1){
        box[i]=m;
        ll curr = getEnergy(box,arr,n);
      //  for(int i=0;i<n;i++) cout<<box[i]<<" "; cout<<" --> "<<curr<<endl;
        if(curr<ans){
            ans = curr;
            see = box;
        }
    }else{
        for(int val = 0;val<=m;val++){
            box[i]=val;
            fun(box,i+1,m-val,n,arr);
        }
    }
}
int main(){
   // freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t;   cin >> t;
      srand(time(NULL));
    while(t--){
        ll n,m;// n= 1+rand()%20;m=1+rand()%10;
        cin >> n >> m ;
        M=m;
        vector<ll> arr(n); for(ll i=0;i<n;i++) //arr[i]=1+rand()%10;
                                cin >> arr[i];
        vector<ll> box(n,0);
        ans = (1LL<<62);
        //fun(box,0,m,n,arr);
        //cout<<ans<< "  ==  ";

        ll fans = 1LL<<62;
        sort(arr.begin(),arr.end());
        for(int c=1;c<=m;c++){
            vector<ll> box(n,0);
            ll M = m;
            for(ll i=0;i<n;i++){
                if(M<c){
                    box[i]=M;M=0; break;
                }else{
                    box[i]=c;
                    M-=c;
                }
            } box[n-1]+=M;M=0; // for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            sort(box.begin(),box.end());
            for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
                fans = min(fans,getEnergy(box,arr,n));
                ll val=box.back(); box.pop_back();
                box.insert(box.begin(),val);
            }
        }    cout<<fans<<endl;
        /*if(ans!=fans){
            cout<<n<<" "<<m<<endl;
            for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
        }*/
    }return 0;
}
