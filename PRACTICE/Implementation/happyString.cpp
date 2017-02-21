#include<bits/stdc++.h>
using namespace std;
bool isHappy(string&str){
    int n = str.length();
    if(n==1)
        return str[0]=='_';
    if((str[0]!='_' && str[0]!=str[1])||(str[n-1]!='_' && str[n-1]!=str[n-2]))
        return false;
    for(int i=1;i<n-1;i++)
        if(str[i]!='_' && str[i]!=str[i-1] && str[i]!=str[i+1])
            return false;
    return true;
}
int main(){
    int t; cin >> t; while(t--){
        string A; cin >> A;
        if(isHappy(A)){
            cout<<"YES"<<endl;
        }else{
            vector<int> freq(26,0);
            int space=0;
            for(int i=0;i<A.length();i++)
                if(A[i]=='_')
                    space++;
                else
                    freq[A[i]-'A']++;
            bool ans = true;
            for(int i=0;i<26;i++)
                if(freq[i]==1)
                    ans = false;
            (ans==false || space==0) ? cout<<"NO"<<endl:cout<<"YES"<<endl;
        }
    } return 0;
}
