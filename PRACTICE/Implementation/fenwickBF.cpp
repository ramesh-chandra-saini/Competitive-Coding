#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getOne(string&A,ll ans=0){
    for(int i=0;i<A.size();i++)
        ans+=(A[i]=='1');
    return ans;
}
int main(){
    //freopen("a.txt","r",stdin);
    ll t,n; cin >> t; while(t--){
        string L1,L2,L3; cin >> L1 >> L2 >> L3 >> n ;
        L1.insert(L1.begin()+0,'0');//simple hack
        ll ans = getOne(L1)+n*getOne(L2)+getOne(L3);
        bool gotFirstZeroFromRight=(ans==0LL);//L is zero, don't do anything ..... : P

        if(gotFirstZeroFromRight==false){
            ll L3ct=0LL;
            for(int i=L3.size()-1LL;i>=0LL && gotFirstZeroFromRight==false;i--)
                if(L3[i]=='0')  gotFirstZeroFromRight=true;
                else L3ct++;
            if(gotFirstZeroFromRight==true){
                ans=ans-(L3ct-1LL);
            }else{
                ll L2ct=0LL;
                for(int i=L2.size()-1LL;i>=0LL && gotFirstZeroFromRight==false;i--)
                    if(L2[i]=='0') gotFirstZeroFromRight=true;
                    else L2ct++;
                if(gotFirstZeroFromRight==true){
                    ans = ans-(L2ct-1LL)-L3ct;
                }else{
                    ll L1ct=0LL;
                    for(int i=L1.size()-1LL;i>=0LL && gotFirstZeroFromRight==false;i--)
                        if(L1[i]=='0') gotFirstZeroFromRight=true;
                        else  L1ct++;
                    ans= ans-(L1ct-1LL)-n*L2ct-L3ct;
                }
            }
        }
        cout<<ans<<endl;
    } return 0;
}
