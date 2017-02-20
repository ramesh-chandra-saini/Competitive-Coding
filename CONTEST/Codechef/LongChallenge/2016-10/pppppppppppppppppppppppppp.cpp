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
            fun(box,0,m,n,arr);


        ll fans = 1LL<<62;

        ll __M = m;
        sort(arr.begin(),arr.end());

        for(ll c=1;c<=m;c++){
            vector<ll> box(n,0);
            bool flag = true;
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
            } box[n-1]+=M;M=0;
            //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<"  ==> ";
            sort(box.begin(),box.end());
            //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<< " ==> ";
            //sort(box.begin(),box.end());
            vector<ll> freq(__M+1,0);
            for(ll i=0;i<n;i++) freq[box[i]]++;
            for(int i=1;i<=__M;i++)  freq[i]+=freq[i-1];
            //cout<<" ==> " ; for(int i=0;i<n;i++)      cout<<freq[__M]-freq[box[i]]<<" "; cout<<endl;
            //for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            fans = min(fans,getEnergy(box,arr,n,freq,__M));

            for(ll i=0;i<n;){
                ll ct =0;
                ll st =i;
                ll x = arr[i];
                while(i<n && x==arr[i]){
                    ct+=box[i];
                    box[i]=0;
                    i++;
                }
                ll sz = (i-st);
                ll D = ct/sz+((ct%sz)?1LL:0LL);
                for(int j=st;j<i;j++)
                    if(ct>D){
                        box[j]=D;
                        ct-=D;
                    }else{
                        box[j]=ct;
                        ct=0;break;
                    }
            }
            sort(box.begin(),box.end());
           // for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<< " ==> ";

            fill(freq.begin(),freq.end(),0);
            for(ll i=0;i<n;i++) freq[box[i]]++;
            for(int i=1;i<=__M;i++)  freq[i]+=freq[i-1];
            //cout<<" ==> " ; for(int i=0;i<n;i++)      cout<<freq[__M]-freq[box[i]]<<" "; cout<<endl;
            //for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            fans = min(fans,getEnergy(box,arr,n,freq,__M));

            fill(box.begin(),box.end(),0);
            M = m,i=0;
            for(ll i=0;i<n;i++){
                if(M<=n-i){
                    for(;i<n;i++){
                        if(M){
                            box[i]=1;
                            M-=1;
                        }else{
                            box[i]=0;
                        }
                    }
                    break;
                }
                if(M<c){
                    ll ct = max(1LL,M/(n-i+1));
                    for(;i<n;i++){
                        if(M<=n-i){
                            for(;i<n;i++){
                                if(M){
                                    box[i]=1;
                                    M-=1;
                                }else{
                                    box[i]=0;
                                }
                            }
                            break;
                        }
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
            } box[n-1]+=M;M=0;
            //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<"  ==> ";
            sort(box.begin(),box.end());

//            for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            //sort(box.begin(),box.end());
            fill(freq.begin(),freq.end(),0);
            for(ll i=0;i<n;i++) freq[box[i]]++;
            for(int i=1;i<=__M;i++)  freq[i]+=freq[i-1];
            //cout<<" ==> " ; for(int i=0;i<n;i++)      cout<<freq[__M]-freq[box[i]]<<" "; cout<<endl;
            //for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            fans = min(fans,getEnergy(box,arr,n,freq,__M));


            fill(box.begin(),box.end(),0);
            M = m,i=0;
            for(ll i=0;i<n;i++){
                if(M<n-i){
                    for(;i<n;i++){
                        if(M){
                            box[i]=1;
                            M-=1;
                        }else{
                            box[i]=0;
                        }
                    }
                    break;
                }
                if(M<c){
                    ll ct = max(1LL,M/(n-i+1));
                    for(;i<n;i++){
                        if(M<n-i){
                            for(;i<n;i++){
                                if(M){
                                    box[i]=1;
                                    M-=1;
                                }else{
                                    box[i]=0;
                                }
                            }
                            break;
                        }
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
            } box[n-1]+=M;M=0;
            //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<"  ==> ";
            sort(box.begin(),box.end());

           // for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            //sort(box.begin(),box.end());
            fill(freq.begin(),freq.end(),0);
            for(ll i=0;i<n;i++) freq[box[i]]++;
            for(int i=1;i<=__M;i++)  freq[i]+=freq[i-1];
            //cout<<" ==> " ; for(int i=0;i<n;i++)      cout<<freq[__M]-freq[box[i]]<<" "; cout<<endl;
            //for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            fans = min(fans,getEnergy(box,arr,n,freq,__M));


            //}
        }
        cout<<fans<<endl;
        /*cout<<ans<<" == "<<fans<<endl;
        if(ans!=fans){
            for(ll i=0;i<n;i++) cout<<see[i]<<" "; cout<<endl;
            cout<<n<<" "<<m<<endl;
            for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
            break;
        }*/
    }return 0;
}
