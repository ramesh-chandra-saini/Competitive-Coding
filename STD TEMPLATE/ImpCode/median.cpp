#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<ll> ds;
void getMedian(){
    ll sz = ds.size();
    float ans;
    if(sz==0LL)
        cout<<"Wrong!"<<endl;
    else if(sz%2LL)
        cout<<ds[(sz/2LL)]<<endl;
    else{
        float ans = (ds[(sz/2)]+ds[(sz/2)-1])/float(2);
        cout<<ans<<endl;
    }
}
void median(vector<char> s,vector<int> X) {
    for(int i=0;i<X.size();i++){
        vector<int>::iterator  it= lower_bound(ds.begin(),ds.end(),X[i]);
        if(s[i]=='r'){
            if(!binary_search(ds.begin(),ds.end(),X[i]))
                cout<<"Wrong!"<<endl;
            else
                ds.erase(it),
                getMedian();
        }else
             ds.insert(it,X[i]),
             getMedian();
       // sort(ds.begin(),ds.end());
    }
}
int main(){

   int N;
   cin >> N;

   vector<char> s;
    vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }
   median(s,X);
   return 0;
}
