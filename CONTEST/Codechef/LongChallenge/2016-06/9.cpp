#include<bits/stdc++.h>
using namespace std;
int main(){


    int N,E,fav; cin >> N >> E;
    map<int,vector<int> > myMap;
    set<int> groups;
    for(int i=1;i<=N;i++) cin >> fav,myMap[fav].push_back(i),groups.insert(fav);
    int disJoinSystem[N+1],id=0;
    for(set<int> :: iterator it=groups.begin();it!=groups.end();++it){
        vector<int> group=myMap[*it];id++;
        for(int i=0;i<group.size();i++){
            cout<<group[i]<<" ";
            disJoinSystem[group[i]]=id;
        }
        cout<<endl;
    }
    map<pair<int,int>,bool> Links;
    int x,y;
    while(E--){
        cin >> x >> y;
        Links[make_pair(x,y)]=Links[make_pair(y,x)]=true;
    }
    int saidPair=0;
    map<int,int> ans;
    for(set<int> :: iterator it=groups.begin();it!=groups.end();++it){
        vector<int> group=myMap[*it];

        for(int i=0;i<group.size();i++){
            for(int j=0;j<=i;j++)
                ans[group[i]]+=Links[make_pair(i,j)];
            for(int j=i+1;j<group.size();j++){
                saidPair+=!Links[make_pair(i,j)];
                ans[group[i]]+=Links[make_pair(i,j)];
            }
        }
    }
     cout<<"saidPair : "<<saidPair<<endl;
     for(int i=1;i<=N;i++)
        cout<<(saidPair+ans[i])<<endl;
    return 0;
}
