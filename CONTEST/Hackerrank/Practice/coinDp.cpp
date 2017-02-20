#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int _count_Num_Way(int coins[],int Num_Of_Coins,int Amount){

    if(Amount==0)
        return 1;
    if(Amount<0)
        return 0;

    if(Amount>=1 && Num_Of_Coins<=0)
        return 0;

    return _count_Num_Way(coins,Num_Of_Coins-1,Amount)+_count_Num_Way(coins,Num_Of_Coins,Amount-coins[Num_Of_Coins-1]);
}
int main(){

    int Amount,Num_Of_Coins;

    memset()
    cin >> Amount >> Num_Of_Coins;

    int coins[Num_Of_Coins];

    for(int i=0;i<Num_Of_Coins;i++)
        cin >> coins[i];

    cout<<_count_Num_Way(coins,Num_Of_Coins,Amount)<<endl;
    return 0;
}
