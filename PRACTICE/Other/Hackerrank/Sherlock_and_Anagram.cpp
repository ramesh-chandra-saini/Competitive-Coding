#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string A,string B){
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    return A==B;
}
int main() {
    int N; cin >> N;
    while(N--){
        string s; cin >> s;
        vector<string> subStr;
        int ans=0;
        for(int i=0;i<s.length();i++){
            string curr,next;curr.clear();
            for(int j=i;j<s.length();j++){
                curr+=s[j],next.clear();
                for(int k=i+1;k<s.length();){
                    if(next.length()<curr.length())
                        next+=s[k++]; //length is less, append more char
                    if(next.length()==curr.length())
                        ans+=isAnagram(next,curr); //check isAnagram or not?
                    if(next.length()>=curr.length()) //if length is more or equal,so erase first char
                        next.erase(next.begin());
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
