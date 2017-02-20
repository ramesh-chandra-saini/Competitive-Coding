#include<bits/stdc++.h>

using namespace std;
#define mfor(i,n) for(int i=0;i<n;i++)
#define LL long long
#define vi vector<int>
#define pb push_back
#define s(n)                    scanf("%d",&n)
#define sl(n)                   scanf("%lld",&n)
#define sf(n)                   scanf("%lf",&n)
#define ss(n)                   scanf("%s",n)
#define myfor(i,a,b) for(i=a;i<=b;i++)
#define IS_ODD( num )   ((num) & 1)
#define IS_EVEN( num )  (!IS_ODD( (num) ))
#define mod 1000000007

long long mp[4];
long long mpp[4];
char s[1000000+1];
long long  ans = 0;

int main()
{
    int t,n;

    mp[0]=mp[1]=mp[2]=0;mpp[0]=mpp[1]=mpp[2]=0;ans = 0;
    cin>>s;

    n = strlen(s);

    mfor(i,n)
        s[i] = s[i]-'0';
    cout<<s<<endl;

    mfor(i,n){

        mpp[ (0+s[i])%3 ] = mp[0];
        mpp[ (1+s[i])%3 ] = mp[1];
        mpp[ (2+s[i])%3 ] = mp[2];
        cout<<"MPP's"<<endl;
        cout<<mpp[0]<<" "<<mpp[1]<<" "<<mpp[2]<<" "<<endl;

        if(!(s[i]&1)){

            if(s[i]%6==0){
                cout<<" 6 "<<ans<<"   "<<mp[0]<<endl;
                ans+= 1LL + (long long)mp[0];
                ans = ans%mod;
            }
            else{

                if(s[i]%3==2)
                    ans+= (long long)mp[1];
                else if(s[i]%3==1)
                    ans+= (long long)mp[2];
                else
                    ans+= (long long)mp[0];
                ans = ans%mod;
            }

            cout<<"ans at "<<(int)s[i]<<" -  "<<ans<<endl;
        }

        mp[0]+=mpp[0];
        mp[1]+=mpp[1];
        mp[2]+=mpp[2];
        mp[(s[i])%3]++;

        mp[0] = mp[0]%mod;
        mp[1] = mp[1]%mod;
        mp[2] = mp[2]%mod;
        cout<<"mp's "<<endl;
        cout<<mp[0]<<" "<<mp[1]<<" "<<mp[2]<<endl;
    }
    cout<<ans<<endl;
}
