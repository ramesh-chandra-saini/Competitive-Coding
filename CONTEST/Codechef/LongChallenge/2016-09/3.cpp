#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;cin >> x >> y;
    int A=y,B=y,C=y;
    int count=0;
    while(1){
        if(A>=x && B>=x && C>=x){
            break;
        }
        switch(count%3){
            case 1 :
                A=B+C-1;
                break;
            case 2 :
                B=A+C-1;
                break;
            default :
                C=A+B-1;
                break;
        }
        count++;
    }
    cout<<count<<endl;
}
