#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum(ll l,ll r,vector<ll>&cumm){
    return cumm[r]-((l>0)?cumm[l-1]:0);
}
void print(multiset<ll> &mst){
    for(multiset<ll> ::iterator it=mst.begin();it!=mst.end();++it)
        cout<<abs(*it)<<" "; cout<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    ll T; cin >> T;
    while(T--){
        ll N,M; cin >> N >> M;
        vector<ll> A(N+1,0),cumm(N+1,0);
        for(ll i=1;i<=N;i++)
            cin >> A[i],
            cumm[i]=cumm[i-1]+A[i];
        vector<ll> B(M+1,0);
        for(ll i=1;i<=M;i++)
            cin >> B[i];
        ll ans = INT_MIN;
        if(M==1){
            ll M1 = B[1];
            for(ll i=M1;i<=N;i++)
             ans = max(ans,sum(i-M1+1,i,cumm));
        }else if(M==2){
            ll M1 = B[1],M2 = B[2];
            vector<ll> second(N+1,0);
            multiset<ll> mst2;
            multiset<ll> ::iterator it;
            ll j=0;
            for(ll i=M2+1;i<M1;i++,j++){
                second[j]=-sum(i-M2+1,i,cumm);
                mst2.insert(second[j]);
            }
            for(ll i=M1,k=0;i<=N;i++,k++,j++){

                ll mx1 = sum(i-M1+1,i,cumm);
                ll mx2 = -(*mst2.begin());
                ans = max(ans,mx1-mx2);
                //cout<<"SET ==> ";print(mst2);
                //cout<<mx1<<" - "<<mx2<<" = "<<ans<<endl;
                second[j] = -sum(i-M2+1,i,cumm);
                mst2.insert(second[j]);
               // cout<<second[i]<<" <== "<<second[j]<<" ==> "<<endl;
                it = mst2.find(second[k]);
                if(it!=mst2.end() && !mst2.empty())
                    mst2.erase(it);
            }

        }else{
           ll M1 = B[1];
            for(ll i=M1;i<=N;i++)
             ans = max(ans,sum(i-M1+1,i,cumm));
        }
        cout<<ans<<endl;
    }
}
