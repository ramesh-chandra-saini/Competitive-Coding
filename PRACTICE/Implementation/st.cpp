#include<bits/stdc++.h>
using namespace std;
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
int main(){

    string str; //cin >> str;
     std::getline(std::cin, str);
     vector<string> P = split(str,' ');
     //for(int i=0;i<P.size();i++) cout<<P[i]; cout<<endl;

    int p=0,m=0;
    for(int i=0;i<P.size();i++){ //count positive and negative
        if(P[i]=="+") p++;
        else if(P[i]=="-") m++;
    }
    int ans=0;
    for(int j=0;j<P[(P.size()-1)].size();j++)
        ans=ans*10+(P[(P.size()-1)][j]-'0');
    int target = ans+m; ++p; //cout<<ans<<endl; //starting value
    if(target<=p*ans && p<=ans+m*ans){ cout<<"Possible"<<endl;
        char last = '+'; int curr=target;
       vector<int> value; value.clear();
       vector<char> sign; sign.clear();
       sign.push_back('+');
        for(int i=0;i<P.size()-2;i++){
            if(P[i]=="+"){ last='+';cout<<"+ ";   sign.push_back('+');
            }else if(P[i]=="-"){ last='-'; cout<<"- ";  sign.push_back('-');
            }else if(P[i]==" ");
            else {
                if(last == '-') {//cout<<"1 ";
                value.push_back(1); }
                else{
                    p--;curr = min(ans,target-p);
                   // cout<<curr<<" ";
                    value.push_back(curr);
                    target -= curr;
                }
            }
        }
        for(int i=0;i<value.size();i++){

            if(value<0){

            }
        }



    }
    else cout<<"Impossible"<<endl;
    return 0;
}
