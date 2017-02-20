#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
     while(t--){
        int act; string origin; cin >> act >> origin;
        int score=0;
        while(act--){
            string activity; cin >> activity;
            if(activity == "CONTEST_WON"){
                int rank; cin >> rank;
                score+=300+max(0,20-rank);
            } else if(activity == "TOP_CONTRIBUTOR")
                score+=300;
            else if(activity=="BUG_FOUND"){
                int severity; cin>>severity;
                score+=severity;
            } else
                score+=50;
        }
        if(origin=="INDIAN") cout<<(score/200)<<endl;
        else cout<<(score/400)<<endl;
     }
     return 0;
}
