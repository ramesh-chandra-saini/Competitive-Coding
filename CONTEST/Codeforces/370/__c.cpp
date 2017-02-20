#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,i; cin >> n >> t;
    string s; cin >> s;
    vector<int> Int;for(i=0;s[i]!='.';++i) Int.push_back(s[i]-'0');
    vector<int> Dec;for(++i;i<n;++i) Dec.push_back(s[i]-'0');
    int carryInt=0;
    int carryDec=0;
    int D=Dec.size();
    for(int d=Dec.size()-1;d>=0;d--){
        if(Dec[d]>=5){
            D=d;
        }
    }
    if(D!=Dec.size()){
        for(int d=D;d>=0 && t>0;d--,t--){
            if(Dec[d]>=5){
                if(d==0)
                    carryDec=1;
                else{
                    Dec[d-1]+=1;
                }
                Dec[d]=0;
                D--;
            }else{
                break;
            }
        }
        carryInt=carryDec;
        for(int I=Int.size()-1;I>=0;I--){
            int temp=Int[I]+carryInt;
            Int[I]=temp%10;
            carryInt=temp/10;
        }
        if(carryInt) cout<<carryInt;
        for(int i=0;i<Int.size();i++) cout<<Int[i];
        if(D>=0) cout<<".";
        for(int j=0;j<=D;j++) cout<<Dec[j]; cout<<endl;
    }else{
        for(int i=0;i<Int.size();i++) cout<<Int[i];
        cout<<".";
        for(int i=0;i<Dec.size();i++) cout<<Dec[i]; cout<<endl;
    }


}
