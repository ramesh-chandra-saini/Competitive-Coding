#include<bits/stdc++.h>
using namespace std;
int main(){

    int n; cin >> n;
    string a,b;a.clear();b.clear();
    cin >> a >> b;b+=b;

    int maxLen=0,idx=0,currLen=0,i=0;
    for(int j=0;j<n && i<n;j++){

        if(a[i]==b[j]){
            currLen++;i++;
            if(currLen>maxLen){
                maxLen=currLen;
                idx=j-currLen+1;
            }
        }else{
            currLen=0;i=0;
        }
    }
    //tricky part is here:P
    for(int j=0;j<n && i<n;j++){
        if(a[i]==b[j]){
            currLen++;i++;
            if(currLen>maxLen){
                maxLen=currLen;
                idx=j-currLen+n+1;//simple hack
            }
        }else{
            currLen=0;i=0; break;//avoid repeating same thing
        }
    }
    cout<<idx<<endl;
    return 0;
}
