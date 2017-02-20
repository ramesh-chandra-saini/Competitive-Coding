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
ll opti(vector<ll>arr,ll m,ll n){
        ll fans = 1LL<<62;
        ll __M = m;
        sort(arr.begin(),arr.end());
        vector<ll>box(n,0);
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
       return fans;
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
    //srand(time(NULL));
    ll t;  scanf("%lld",&t);
    while(t--){
        ll n,m;  //n= 1+rand()%10;m=1+rand()%15;
        scanf("%lld%lld",&n,&m);
        vector<ll> arr(n); for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);//arr[i]=1LL+rand()%100;//
        ans = 1LL<<62;
        if(n<=10){
            vector<ll>box(n,0);
            fun(box,0,m,n,arr);

        }
        ll ans2 = (1LL<<62);
        /*if(m<=10){
            ans2 = opti(arr,m,n);
            cout<<min(ans,ans2)<<endl;
            continue;
        }*/

        //fun(box,0,m,n,arr);

        ll fans = 1LL<<62;
        ll __M = m;
        sort(arr.begin(),arr.end());
        for(ll c=1;c<=m;c++){
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
            } box[n-1]+=M;M=0;
            //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<"  ==> ";
            sort(box.begin(),box.end());

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
            ll sum =0; for(int i=0;i<n;i++) sum+=box[i];
           // for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<< "  "; cout<<" <<< "<<sum<<endl;
            if(sum==__M){
            sort(box.begin(),box.end());
            fill(freq.begin(),freq.end(),0);
            for(ll i=0;i<n;i++) freq[box[i]]++;
            for(int i=1;i<=__M;i++)  freq[i]+=freq[i-1];
            //cout<<" ==> " ; for(int i=0;i<n;i++)      cout<<freq[__M]-freq[box[i]]<<" "; cout<<endl;
            //for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            fans = min(fans,getEnergy(box,arr,n,freq,__M));

            }
            //}
        }
        cout<<min(fans,min(ans2,ans))<<endl;
        /*cout<<ans<<" == "<<fans<<endl;
        if(ans!=fans){
            for(ll i=0;i<n;i++) cout<<see[i]<<" "; cout<<endl;
            cout<<n<<" "<<m<<endl;
            for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
            break;
        }*/
    }return 0;
}
