#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll N,ll base){
    while(N){
        if(N%base!=1LL)
            return false;
        N/=base;
    }
    return true;
}
ll checker(ll rem){
    while(rem){
        if(rem%10LL!=1LL)
            return 0LL;
        rem/=10LL;
    }
    return 1LL;
}
ll get(ll uppr){
    ll num = 1LL;
    while(num*10LL+1LL<=uppr)
        num=num*10+1LL;
    return num;
}

ll dir(ll N,ll base){


    while(N){
        if((N%base)>1)
            return 1LL;//right
        N/=base;
    }
    return 0LL;
}
void bin(ll state,ll low,ll high,ll N,ll &ans){

    if(low>high)
        return ;
    ll mid = (low+high)/2LL;
     cout<<mid<<endl;
    if(check(N,mid)==true){
        ans=min(ans,mid);
    }
    ll d = dir(N,mid);

     if( check(N/mid,10) ==true){
         if(state==0LL){ //right
        if(d==1LL){
            bin(1LL,mid+1LL,high,N,ans);
        }else{
            bin(0LL,low,mid-1LL,N,ans);
        }
    }else{
        if(d==1LL){
        bin(0LL,low,mid-1LL,N,ans);
        }else{
            bin(1LL,mid+1LL,high,N,ans);
        }
    }
    }else{
    if(state==0LL){ //right
        if(d==1LL){
            bin(1LL,mid+1LL,high,N,ans);
        }else{
            bin(0LL,low,mid-1LL,N,ans);
        }
    }else{
        if(d==1LL){
        bin(0LL,low,mid-1LL,N,ans);
        }else{
            bin(1LL,mid+1LL,high,N,ans);
        }
    }
    }
//    bin(low,mid-1LL,N,ans);
  //  bin(mid+1LL,high,N,ans);
}
int main(){

    //freopen("in.txt","r",stdin);
    //freopen("opt.txt","w",stdout);
    ll t;cin >> t;
    for(ll T=1LL;T<=t;T++){
        ll N;cin>>N;
        ll ans = INT_MAX;

        bin(0LL,2LL,N,N,ans);
        bin(1LL,2LL,N,N,ans);


        cout<<"Case #"<<T<<": "<<ans<<endl;
    }


    return 0LL;

}

