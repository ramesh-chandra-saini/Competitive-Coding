#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
void read(int &x){
    x=0;
    register char c=gc();
    for(;c<'0' || c>'9';c=gc());
    for(;c>='0' && c<='9';c=gc()){
        x=(x<<3)+(x<<1)+(c-'0');
    }
}
void write(char *c){
   for(int i=0;c[i]!='\0';i++) pc(c[i]); pc('\n');
}
bool IsAwkwardNess(int id,set<int> &table,vector<vector<int> > &graph){
    for(set<int>::iterator it=table.begin();it!=table.end();++it)
        if(graph[id][(*it)]==0)
            return true;
    return false;
}
int main(){
    int t,n,m,x,y; read(t);
    char *yes="YES",*no="NO";
    set<int>left,right;
    set<pair<int,int> > pool,exclude,include;
    bool ans=true,isPlaceAny=false;
    while(t--){
        read(n),read(m);
        vector<vector<int> > graph(n+1,vector<int>(n+1,0));
        while(m--)
            read(x),read(y),graph[x][y]=graph[y][x]=1;
        ans=true,pool.clear(),right.clear(),left.clear();  left.insert(1);
        for(int i=2;i<=n;i++)
            pool.insert(make_pair(left.size()+right.size(),i));
        map<int,int> regFreq;regFreq.clear();
        while(!pool.empty()){
            isPlaceAny=false;
            exclude.clear(),include.clear();
            for(set<pair<int,int> > ::iterator it=pool.begin();it!=pool.end();++it){
                bool leftAwkwardNess = IsAwkwardNess(it->second,left,graph);
                bool rightAwkwardNess = IsAwkwardNess(it->second,right,graph);
                if(leftAwkwardNess && rightAwkwardNess){
                    ans=false;  break;
                }
                else if(!leftAwkwardNess && rightAwkwardNess){
                    exclude.insert(*it);
                    left.insert(it->second);
                    isPlaceAny=true;
                } else if(leftAwkwardNess && !rightAwkwardNess){
                    exclude.insert(*it);
                    right.insert(it->second);
                    isPlaceAny=true;
                } else{ //just pull and push with current placed elements
                    regFreq[it->second]++;
                    if(regFreq[it->second]>15) break;
                    if(it->first!=left.size()+ right.size()){
                        exclude.insert(*it);
                        include.insert(make_pair(left.size()+right.size(),it->second));
                    }
                }
            }
            if(ans==false) break;//impossible configuration
            for(set<pair<int,int> >::iterator it=exclude.begin();it!=exclude.end();++it)
                pool.erase(*it);
            for(set<pair<int,int> >::iterator it=include.begin();it!=include.end();++it)
                pool.insert(*it);
            if(isPlaceAny==false){
                set<pair<int,int> > ::iterator it=pool.begin();
                pool.erase(*it); left.insert(it->second);
            }
        }
        (left.size()+right.size()==n)?write(yes):write(no);
    } return 0;
}
