
#include<bits/stdc++.h>
using namespace std;

int K=1;
int N;
void shift( string &str,int first,int last){

    cout<<first<<" "<<last<<endl;
    if(first>=str.length() || last>=str.length()) return ;

    char c=str.at(last);
    str.erase(str.at(last));
    if(first){
            str.insert(str.begin()+first-1,c);
    }
    else str.insert(str.begin(),c);
}
void permut(string & str, int l, int r){

    cout<< str<<endl;
    if(l==r){ cout<< str<<endl; return;}
    for(int i=l;i+K-1<=r;i++){


        if(l<N && i+K-1<N)shift(str,l,i+K-1);
                cout<<l+1<<" "<<r<<endl;
        if(l+1<N && r<N)permut(str,l+1,r);
        if(l<N && i+K-1<N)shift(str,l,i+K-1);
    }
}

int main(){


    string str;

    cin >> str;
    N=str.length();
    permut(str,0,str.length()-1);
    return 0;
}
