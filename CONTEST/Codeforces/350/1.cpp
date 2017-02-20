#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int n,p;
    cin >> n >> p;

    vector<string> S(n);
    for(int i=0;i<n;i++){
        cin >> S[i];
    }
    long long int ans=1;
    for(int i=n-2;i>=0;i--){
         if(S[i]=="half")
            ans=ans*2+0;
        else ans=ans*2+1;
    }

    long long int final_ans=0;
    while(ans){

        final_ans+=(ans*p)/2;
        ans/=2;
    }
    cout<<final_ans<<endl;
    return 0;
}
