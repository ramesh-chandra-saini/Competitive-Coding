#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(char c,ll n,ll m,vector<string> game,ll K){
    //cout<<c<<endl;
    bool ans = false;
    //horizontal
        for(ll i=0;i<n;i++){
            ll curr = 0;
            for(ll j=0;j<m;j++){
                curr=(game[i][j]==c)? (curr+1):0;
                ans=(curr>=K)?true:ans;
                //cout<<curr<<" ";
            } //cout<<endl;
        }
    //vertical
        for(ll j=0;j<m;j++){
            ll curr = 0;
            for(ll i=0;i<n;i++){
                curr=(game[i][j]==c)? (curr+1):0;
                ans=(curr>=K)?true:ans;
                //cout<<curr<<" ";
            } //cout<<endl;
        }

        for(ll k=0;k<m;k++){
            ll curr = 0;
            for(ll i=0,j=k;i<n && j<m;i++,j++){
                curr=(game[i][j]==c)? curr+1:0;
                ans=(curr>=K)?true:ans;
                //cout<<curr<<" ";
            } //cout<<endl;
        }
        for(ll k=0;k<n;k++){
            ll curr = 0;
            for(ll i=k,j=0;i<n && j<m;i++,j++){
                curr=(game[i][j]==c)? curr+1:0;
                ans=(curr>=K)?true:ans;
                //cout<<curr<<" ";
            } //cout<<endl;
        }
        for(ll k=0;k<n;k++){
            ll curr = 0;
            for(ll i=k,j=0;i>=0 && j<m;i--,j++){
                curr=(game[i][j]==c)? curr+1:0;
                ans=(curr>=K)?true:ans;
                //cout<<curr<<" ";
            } //cout<<endl;
        }

        for(ll k=0;k<m;k++){
            ll curr = 0;
            for(ll i=n-1,j=k;i>=0 && j<m;i--,j++){
                curr=(game[i][j]==c)? curr+1:0;
                ans=(curr>=K)?true:ans;
                //cout<<curr<<" ";
            } //cout<<endl;
        }
       //cout<<c<<" final "<<ans<<endl;
        return ans;
}
int main(){
    ll t; cin >> t; while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vector<string> game(n); for(ll i=0;i<n;i++) cin >> game[i];
        //horizontal
        bool O = check('O',n,m,game,k);
        bool X = check('X',n,m,game,k);
        //cout<<O<<" "<<X<<endl;
        if(O==true && X == true){
            cout<<"NONE"<<endl;
        }else if(O==false && X==true){
            cout<<"LOSE"<<endl;
        }else if(O==true && X==false){
            cout<<"WIN"<<endl;
        }else if(O==false && X==false){
            cout<<"NONE"<<endl;
        }
    } return 0;
}
