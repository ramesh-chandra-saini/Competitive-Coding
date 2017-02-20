#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000000
ll idx=0;
bool bin(vector<ll> &fib,ll s,ll e,ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(fib[m]==key){  return true;}
    if(fib[m]<key) return bin(fib,m+1,e,key);
    return bin(fib,s,m-1,key);
}
int main(){
    clock_t s=clock();
	vector<ll> fib;fib.clear(); fib.push_back(1); fib.push_back(2);
	ll a=1,b=2,c,last=2;
	while(a+b<=MAX)
        c=a+b,fib.push_back(c),a=b,b=c;

    vector<pair<ll,ll> > fibList(100000000);
    fibList[0]=(make_pair(1,1)); fibList[1]=(make_pair(2,1));
    ll loop=100000000,j=1,i=0,size=2;a=0,b=0; idx=2;
    for(i=0;i<j && loop--;){ a++;
        if(bin(fib,0,fib.size()-1, fibList[i].first+fibList[j].first)==true){ idx++;last=fibList[i].first+fibList[j].first;
            fibList[size++]=make_pair(fibList[i].first+fibList[j].first,1);j=size-1;i=0;}//set j at last fibo number
        else if((fibList[i].second+fibList[j].second<=10))
            fibList[size++]=make_pair(fibList[i].first+fibList[j].first, fibList[i].second+fibList[j].second),b+=(fibList[i].second+fibList[j].second>10)?1:0,i++;
        if(i==j){
            if(idx<fib.size()){last=fib[idx++];
                fibList[size++]=make_pair(last,1);i=0;j=size-1;
            }
        }
    }
    cout<<i<<"i :: j"<<j<<" --|| LAST ITEM"<<last<<endl;
    cout<<"REPORT : \nA : "<<a<<"  \nB :  "<<b<<" \nA-B  : "<<a-b<<endl;
    //for(ll i=0;i<fibList.size();i++) cout<<fibList[i].first<<"  "<<fibList[i].second<<endl; cout<<endl;
	clock_t e=clock();
	double d = (e-s)/CLOCKS_PER_SEC;
	cout<<endl<<d<<endl;
	return 0;
}
