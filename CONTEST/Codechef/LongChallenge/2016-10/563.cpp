#include<bits/stdc++.h>
using namespace std;
#define ll long long
void binSearch(vector<ll>&B,ll low,ll high,ll key,ll &idx){
    if(low>high)    return;
    ll mid = (low+high)/2;
    if(B[mid]>=key) idx = mid,binSearch(B,low,mid-1,key,idx);
    else  binSearch(B,mid+1,high,key,idx);
}
ll getEnergy(vector<ll>&box,vector<ll>&arr,ll n,ll Energy=0LL){
    map<ll,ll> my; for(ll i=0;i<n;i++) my[box[i]]++;
    ll N = my.size(),p=0;
    vector<ll>B(N),freq(N);
    for(map<ll,ll>::iterator it = my.begin();it!=my.end();it++,p++)
        B[p]=(it->first),freq[p]=(it->second);
    for(int i=1;i<N;i++)   freq[i]+=freq[i-1];
   for(ll i=0;i<n;i++){
        ll idx = N-1;
        binSearch(B,0,N-1,box[i],idx);
        ll ct =freq[N-1]-freq[idx];
        Energy+=ct*arr[i];
    }     return Energy;
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
    ll t;  scanf("%lld",&t);
    while(t--){
        ll n,m;scanf("%lld%lld",&n,&m);
        vector<ll> arr(n); for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);
        ans = 1LL<<62;
        vector<ll> box(n,0);
        fun(box,0,m,n,arr);

        ll fans = 1LL<<62;
        sort(arr.begin(),arr.end());
        if(m%n==0){
            printf("0\n");
            continue;
        }
        for(ll c = 1 ; c<= m;c++){
          fill(box.begin(),box.end(),0);
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
            } box[n-1]+=M;M=0; for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            sort(box.begin(),box.end());
            fans = min(fans,getEnergy(box,arr,n));
            /*
            for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
                fans = min(fans,getEnergy(box,arr,n));
                ll val=box.back(); box.pop_back();
                box.insert(box.begin(),val);
            }*/
            if(ans!=fans){
                cout<<ans<<" == "<<fans<<endl;
                for(int i=0;i<n;i++) cout<<see[i]<<" "; cout<<endl;
                cout<<n<<" "<<m<<endl;
                for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
            }

    }return 0;
}
