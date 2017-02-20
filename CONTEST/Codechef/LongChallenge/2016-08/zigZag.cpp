#include<bits/stdc++.h>
using namespace std;
#define height first
#define rate second
bool isZigZag(vector<pair<int,int> >&data,int typeOfZigZag){
    if(data.size()<=1) return true;

    if(data.size()<=2) return true;
    if(data[0]>data[1]){
        for(int i=1;i<data.size()-1;i++) //local minima
            if(data[i-1].height>=data[i].height && data[i].height<=data[i+1].height);
            else return false;
        return true;
    }else{
        for(int i=1;i<data.size()-1;i++)//local maxima
            if(data[i-1].height<=data[i].height && data[i].height>=data[i+1].height);
            else return false;
        return true;
    }
}
int main(){
    int t; cin >> t; while(t--){
        int n;cin >> n; vector<pair<int,int> > data(n); for(int i=0;i<n;i++) cin>>data[i].height>>data[i].rate;
        int flag=0,day=0,loop=10,typeOfZigZag=0;
        vector<int> ans;

        do{

            if(isZigZag(data)==true) ans.push_back(day,typeOfZigZag),flag++;
            else flag=0;
            for(int i=0;i<n;i++)
                data[i].height+=data[i].rate;
            day++;
        }while(loop--);
        cout<<ans.size()<<" ";for(int i=0;i<ans.size();i++) cout<<ans[i]<<" "; cout<<endl;
    } return 0;
}
