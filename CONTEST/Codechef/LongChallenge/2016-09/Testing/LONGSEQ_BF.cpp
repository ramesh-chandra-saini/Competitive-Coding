#include<bits/stdc++.h>
using namespace std;
bool isAllDigitSame(string s){
    int countZero = 0;
    int countOne = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0') countZero++;
        else countOne++;
    }
    return s.length()==countZero || s.length()==countOne;
}
string getFlippedOne(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            s[i]='0';
            return s;
        }
    }
    s[0]='1';
    return s;
}
string getFlippedZero(string s){
  for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            s[i]='1';
            return s;
        }
    }
    s[0]='0';
    return s;
}
int main(){

    int  t; cin >> t;
    while(t--){
        string s; cin >> s;
        string  oneFlip = getFlippedOne(s);
        string zeroFlip = getFlippedZero(s);
        if(isAllDigitSame(oneFlip) || isAllDigitSame(zeroFlip)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    } return 0;
}
