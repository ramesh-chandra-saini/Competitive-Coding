#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main(){
    ll T; cin >> T;
    while(T--){
        ll N; cin >> N;
        ll A[N]; for(ll i=0;i<N;i++) cin >> A[i];
        ll ans = 1;
        if(A[0]==-1) //first has only one choice
            A[0]=1;
        if(A[0]!=1) //invalid given array
            ans = 0;
        int num = 0; //no restriction
        for(int i=N-1;i>=0;i--){
            if(num){ //follow restriction
                if(A[i]==-1)//you can place your number
                    A[i]=num;
                else if(A[i]!=num) // invalid arrray
                    ans = 0;
                num--;
            }else{ //no restriction
                    if(A[i]>1)
                        num = A[i]-1;
            }
        }
        ans= (num)?0:ans; //finally num should be zero only
        for(ll i=0;i<N;i++)
            ans = (A[i]==-1)?(ans*2)%mod:ans;
        cout<<ans<<endl;
    }
    return 0;
}
