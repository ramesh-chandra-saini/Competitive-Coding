#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[1002][1002][2];
ll cp[1002][1002][2];
ll twos(ll num,ll ans=0){
    while(num>0 && num%2==0)
        ans++,num=num/2;
    return(ans);
}
ll fives(ll num,ll ans=0){
    while(num>0 && num%5==0)
        ans++,num/=5;
    return(ans);
}
int main(){
    ll n;cin>>n;
    for(ll i=0;i<=1000;i++)
        for(ll j=0;j<=1000;j++)
            dp[i][j][0]=dp[i][j][1]=INT_MAX;

    dp[0][1][0]=0;
    dp[0][1][1]=0;
    dp[1][0][0]=0;
    dp[1][0][1]=0;
    bool flag = false;
    string zero="";
    for(ll i=1;i<=n;i++){
        for(ll j=1,num;j<=n;j++){
            cin >> num;

            dp[i][j][0]=twos(num);
            dp[i][j][1]=fives(num);
            cp[i][j][0]=twos(num);
            cp[i][j][1]=fives(num);

            if(num==0 && flag==false){
                flag=true;
                zero="";
                for(ll k=2;k<=i;k++)
                    zero.push_back('D');
                for(ll k=1;k<n;k++)
                    zero.push_back('R');
                for(ll k=i;k<n;k++)
                    zero.push_back('D');
            }
        }
    }
   // for(ll i=1;i<=n;i++,cout<<endl)for(ll j=1;j<=n;j++)cout<<"["<<cp[i][j][0]<<","<<cp[i][j][1]<<"] ";
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){

           ll a=min(dp[i][j][0]+dp[i-1][j][0],dp[i][j][1]+dp[i-1][j][1]);
           ll b=min(dp[i][j][0]+dp[i][j-1][0],dp[i][j][1]+dp[i][j-1][1]);
            if(a==b){
                if(dp[i-1][j][0]==dp[i][j-1][0]  && dp[i-1][j][1]==dp[i][j-1][1]){
                    dp[i][j][0]+=dp[i-1][j][0];
                    dp[i][j][1]+=dp[i-1][j][1];
                }else if(dp[i-1][j][0]!=dp[i][j-1][0]  && dp[i-1][j][1]==dp[i][j-1][1]){
                    if(dp[i-1][j][0]<dp[i][j-1][0]){
                        dp[i][j][0]+=dp[i-1][j][0];
                        dp[i][j][1]+=dp[i-1][j][1];
                    }else{
                        dp[i][j][0]+=dp[i][j-1][0];
                        dp[i][j][1]+=dp[i][j-1][1];
                    }
                }else if(dp[i-1][j][0]==dp[i][j-1][0]  && dp[i-1][j][1]!=dp[i][j-1][1]){
                    if(dp[i-1][j][1]<dp[i][j-1][1]){
                        dp[i][j][0]+=dp[i-1][j][0];
                        dp[i][j][1]+=dp[i-1][j][1];
                    }else{
                        dp[i][j][0]+=dp[i][j-1][0];
                        dp[i][j][1]+=dp[i][j-1][1];
                    }
                }else{
                    dp[i][j][0]+=dp[i-1][j][0];
                    dp[i][j][1]+=dp[i-1][j][1];
                }
           } else if(a<b){
                dp[i][j][0]+=dp[i-1][j][0];
                dp[i][j][1]+=dp[i-1][j][1];
           }else{
                dp[i][j][0]+=dp[i][j-1][0];
                dp[i][j][1]+=dp[i][j-1][1];
           }
        }
    }
    string ans="";
    for(ll i=n,j=n;;){
        if(i>1 && dp[i][j][0]-cp[i][j][0]==dp[i-1][j][0] && dp[i][j][1]-cp[i][j][1]==dp[i-1][j][1]){
            ans.push_back('D');
            i--;
        }else if(j>1 && dp[i][j][0]-cp[i][j][0]==dp[i][j-1][0] && dp[i][j][1]-cp[i][j][1]==dp[i][j-1][1]){
            ans.push_back('R');
            j--;
        }else{
            break;
        }
    } //cout<<ans<<endl;
    if(flag==true && min(dp[n][n][0],dp[n][n][1])>1){
        cout<<"1"<<endl;
        cout<<zero<<endl;
        return 0;
    }

    cout<<min(dp[n][n][0],dp[n][n][1])<<endl;
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];cout<<endl;

    return 0;
}
