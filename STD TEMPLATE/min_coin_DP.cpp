#include<bits/stdc++.h>
using namespace std;

int main(){


    int T;
    cin>>T;

    while(T--){

        int coins;

        cin>>coins;

        vector<int>value(coins);
        //value: 1 coins is always present
        for(int i =0; i< coins; i++) cin>>value.at(i);
        sort(value.begin(),value.end());

        int Q;
        cin>>Q;

        while(Q--){

            int amount;
            cin>>amount;

            int dp[amount+1];
            dp[0]=0;

            vector<int> used_coins; used_coins.clear();
            for(int curr=1,j=0;curr<=amount;curr++){

                int optimal=INT_MAX;
                if(j< coins && curr==value.at(j)){

                    used_coins.push_back(value.at(j++));
                }
                for(int i=0;i<used_coins.size();i++){

                    optimal=min(optimal,dp[curr-used_coins.at(i)]+1);
                }
                dp[curr]=optimal;
            }
            cout<< dp[amount]<<endl;
        }
    }
}
