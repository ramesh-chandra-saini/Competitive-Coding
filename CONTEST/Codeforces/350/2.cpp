/**

    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATKA SURATHKAL
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

   ll n;
   cin >> n;

   ll arr[n];
   for(ll i=0;i<n;i++)
        cin >> arr[i];

    string s;
    cin >> s ;

    ll price=0,checker=0,final_ans=0;

    //Calculate Current price
    for(int i=0;i<n;i++)
        if(s[i]=='B') price+=arr[i];
    checker=price;final_ans=price;

    //selecting prefix and calculate maximum ans
    for(int i=0;i<n;i++){

        if(s[i]=='A') checker+=arr[i];
        else checker-=arr[i];
        final_ans=max(final_ans,checker);
    }
    checker=price;

    //selecting suffix and calculte maximum ans
    for(int i=n-1;i>=0;i--){
        if(s[i]=='A') checker+=arr[i];
        else checker-=arr[i];
        final_ans=max(final_ans,checker);
    }

    // print final ans to judge
    cout<<final_ans<<endl;
    return 0;
}
