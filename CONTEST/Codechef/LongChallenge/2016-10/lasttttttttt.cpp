#include<bits/stdc++.h>
using namespace std;
#define ll long long
void binSearch(vector<ll>&B,ll low,ll high,ll key,ll &idx){
    if(low>high)    return;
    ll mid = (low+high)/2;
    if(B[mid]>=key) idx = mid,binSearch(B,low,mid-1,key,idx);
    else  binSearch(B,mid+1,high,key,idx);
}
ll getEnergy(vector<ll>&box,vector<ll>&arr,ll n,vector<ll>&freq,ll M){
ll Energy=0LL;
   for(ll i=0;i<n;i++){
        ll ct =freq[M]-freq[box[i]];
        Energy+=ct*arr[i];
    }
         return Energy;
}
ll get(vector<ll>&box,vector<ll>&arr,ll n,ll Energy=0LL){
    for(ll i=0;i<n;i++){
        ll ct =0;
        for(ll j=0;j<n;j++)
            ct+=(box[j]>box[i]);
        Energy+=ct*arr[i];
    }    return Energy;
}
ll ans;
vector<ll> see;
void fun(vector<ll>box,ll i,ll m,ll n,vector<ll>&arr){
    if(m==0||i==n-1){
        box[i]=m;
        ll curr = get(box,arr,n);
       //for(int i=0;i<n;i++) cout<<box[i]<<" "; cout<<" --> "<<curr<<endl;
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
void opti(vector<ll>arr,vector<ll>box,ll m,ll n){
 ll fans = 1LL<<62;
        ll __M = m;
        sort(arr.begin(),arr.end());
        fill(box.begin(),box.end(),0);
        for(int pt = __M;pt>=1;pt--){
            ll tott = __M;
            for(int j=n-1;j>=0;j--)
                if(tott>pt)
                    box[j]=pt,tott-=pt;
                else
                    box[j]=tott,tott=0;
            if(tott)
                break;
            while(true){
                sort(box.begin(),box.end());
                vector<ll> freq(__M+1,0);
                for(ll i=0;i<n;i++) freq[box[i]]++;
                for(int i=1;i<=__M;i++)  freq[i]+=freq[i-1];
                ll curr = getEnergy(box,arr,n,freq,__M);
                if(curr>fans){
                    break;
                }
                fans = min(fans,curr);

              //  for(int i=0;i<n;i++) cout<<box[i]<<" "; cout<<" == ";
                bool flag = false;
                for(int i=0;i<n;i++){
                    if(box[i]>=2){
                    flag = true;
                    ll ct = box[i]-1;
                    ll carry = 0;
                    for(int j=i;j>=0;j--){
                        if(box[j]+carry>ct){
                            ll temp = box[j]+carry;
                            box[j]=ct;
                            carry = temp-box[j];
                        }else{
                            box[j]+=carry;
                            break;
                        }
                    } break;
                }
            }
            //for(int i=0;i<n;i++) cout<<box[i]<<" "; cout<<" --> ";cout<<endl;
             ll sum =0;
            for(int i=0;i<n;i++)
                sum+=box[i];
            if(flag==false || sum!=__M)
                break;
            }
        }
        cout<<fans<<endl;

}
int main(){
    //freopen("in.txt","r",stdin);
    srand(time(NULL));
    ll t;  scanf("%lld",&t);
    while(t--){
        ll n,m;  //n= 1+rand()%7;m=1+rand()%13;
        scanf("%lld%lld",&n,&m);
        vector<ll> arr(n); for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);
                                   //arr[i]=1LL+rand()%77;
        ans=1LL<<62;
            vector<ll> box(n,0);
            //fun(box,0,m,n,arr);
        opti(arr,box,m,n);



    }return 0;
}
