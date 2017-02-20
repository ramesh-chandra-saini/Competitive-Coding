#include<bits/stdc++.h>
using namespace std;
int getExtra(int type){
    if(type<4) return 0;
    else if(type==4) return 1;
    else if(type==5) return 2;
    else return 4;
}
int main(){
    int t; cin >> t; while(t--){
        int N; cin >> N;
        int score[N];
        int mxScore=INT_MIN;
        for(int i=0;i<N;i++){
            int k; cin >> k;
            map<int,int> type; type.clear();
            for(int j=0,val;j<k;j++)
                cin >> val,type[val]++;
            //for(map<int,int>::iterator it=type.begin();it!=type.end();it++) cout<<it->first<<"["<<it->second<<"]"<<" "; cout<<endl;
            score[i]=k;
            for(;!type.empty();){
                int mnFr=INT_MAX;
                //for(map<int,int>::iterator it=type.begin();it!=type.end();it++) cout<<it->first<<"["<<it->second<<"]"<<" "; cout<<endl;
                for(map<int,int>::iterator it=type.begin();it!=type.end();it++)
                    mnFr=min(mnFr,it->second);
                score[i]+=mnFr*getExtra(type.size());
                map<int,int> temp; temp.clear();
                for(map<int,int>::iterator it=type.begin();it!=type.end();++it){
                    if(mnFr!=it->second){
                        temp[it->first]=it->second-mnFr;
                    }
                }
                type=temp;
                //for(map<int,int>::iterator it=type.begin();it!=type.end();it++) cout<<it->first<<"["<<it->second<<"]"<<" "; cout<<endl;
            }
            mxScore=max(mxScore,score[i]);
        }
        int id=0,fr=0;
        for(int i=0;i<N;i++){
            if(score[i]==mxScore){
                fr++,  id=i;
            }
        }
        if(fr>1){
            cout<<"tie"<<endl;
        } else {
            if(id==0){
                cout<<"chef"<<endl;
            } else{
                cout<<(id+1)<<endl;
            }
        }

    } return 0;
}
