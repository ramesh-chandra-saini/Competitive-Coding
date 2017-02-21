#include<bits/stdc++.h>
using namespace std;
int get(int pos,vector<int>&freq,int curr=0){
    for(int i=0;i<=200;i++)
        if(curr+freq[i]>=pos)
            return i;
        else
            curr+=freq[i];
}
int main(){
    int n,d; cin >> n >> d;
    vector<int> arr(n+1); for(int i=1;i<=n;i++) cin >> arr[i];
    int ans=0;
    vector<int> freq(201,0);
    for(int i=1;i<=d;i++)
        freq[arr[i]]++;
    for(int i=d+1,median;i<=n;i++){
/*        for(int i=0;i<=200;i++)
            if(freq[i])
                cout<<i<<"("<<freq[i]<<")  "; cout<<endl;*/
        if(d%2)
            median = get((d+1)/2,freq)+get((d+1)/2,freq);
        else
            median = get(d/2,freq)+get(d/2+1,freq);
        if(arr[i]>=median)
            ans++;
  //      cout<<i<<")"<<median<<"-->"<<ans<<endl;
        freq[arr[i-d]]--;
        freq[arr[i]]++;
    }// cout<<endl;
    cout<<ans<<endl;
}
