#include<bits/stdc++.h>
using namespace std;
#define size 1000000
int arr[size+1];
bool IsPalin(int value){
    int revValue=0,temp=value;
    while(temp){
        revValue=revValue*10+temp%10;temp/=10;
    }
    return revValue == value;
}
void solve(){
    int palindrome=0;
    for(int i=1;i<=size;i++){
        if(IsPalin(i)){
            int d=sqrt(i);
            bool flag=false;
            for(;d>=100;d--){
                if(i%d==0){
                    if(i/d>=100){
                        palindrome = max(palindrome,i);
                    }
                }
            }
        }
        arr[i]=palindrome;
    }
}
int main(){

    solve();
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cout<<arr[n]<<endl;
    }
    return 0;
}
