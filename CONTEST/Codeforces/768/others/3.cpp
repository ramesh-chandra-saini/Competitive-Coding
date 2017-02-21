#include<bits/stdc++.h>
using namespace std;
void print(map<int,int> mp){
    for(map<int,int> :: iterator it = mp.begin();it!=mp.end();++it)
        cout<<it->first<<" "; cout<<endl;
}
int main(){
   freopen("in.txt","r",stdin);
   clock_t  runtime = clock();
    int n,k,x; cin >> n >> k >> x;
    map<int,int> mp;
    for(int i=0,x;i<n;i++)
        mp[(i%1000)]++;
    ///print(mp);
    while(k--){
        map<int,int> curr;curr.clear();
        int total = 0;
        for(map<int,int> :: iterator it = mp.begin();it!=mp.end();++it){
            int num = it->first,freq = it->second,f=it->second;
            //cout<<num<<"["<<freq<<"] ";
            if(total%2==0){
                    //cout<<"even"<<" ";
                    int __num = (num ^ x), __freq = freq-(freq/2);
                    if(__freq)
                        curr[__num]+=__freq;//,cout<<__num<<" _ "<<__freq<<endl;
                    freq/=2;
                    if(freq)
                        curr[num]+=freq;//,cout<<num<<" "<<freq<<endl;
            }else{
                    //cout<<"odd"<<" ";
                    int __num = (num ^ x), __freq = (freq/2);
                    if(__freq)
                        curr[__num]+=__freq;//cout<<__num<<" _ "<<__freq<<endl;
                    freq=freq-(freq/2);
                    if(freq)
                        curr[num]+=freq;//cout<<num<<" "<<freq<<endl;
            } //cout<<endl;
            total+=f;
        } //cout<<endl;
        //print(curr);
        mp.clear();
        mp =curr;
    }
    int mn = INT_MAX,mx = INT_MIN;
    for(map<int,int>::iterator it = mp.begin();it!=mp.end();++it)
        mn = min(mn,it->first),mx = max(mx,it->first);//,cout<<it->first<<" ";
    cout<<mx<<" "<<mn<<endl;
    runtime = clock()-runtime;
    double time = (runtime*1.0)/CLOCKS_PER_SEC;
    cout<<time<<endl;
}
