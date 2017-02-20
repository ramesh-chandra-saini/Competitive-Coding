#include<bits/stdc++.h>
using namespace std;
bool IsAwkwardNess(int id,set<int> &table,vector<vector<int> > &graph){
    for(set<int>::iterator it=table.begin();it!=table.end();++it){
        if(graph[id][(*it)]==0){
            return true;
        }
    }
    return false;
}
int main(){
    int t ; scanf("%d",&t); while(t--){
        int n,m;  scanf("%d%d",&n,&m);//cin >> n >> m;
        vector<vector<int> > graph(n+1,vector<int>(n+1,0));
        while(m--){
            int x,y; scanf("%d%d",&x,&y);//cin >> x >> y;
            graph[x][y]=1;graph[y][x]=1;
        } //for(int i=1;i<=n;i++) { for(int j=1;j<=n;j++) cout<<graph[i][j]<<" "; cout<<endl;}
        set<int> left; left.clear();         left.insert(1); //cout<<"1 placed at Left"<<endl;
        set<int> right; right.clear();
        set<pair<int,int> > pool;
        int placed=left.size()+right.size();
        for(int i=2;i<=n;i++)
            pool.insert(make_pair(placed,i));
        bool ans=true;
        while(!pool.empty()){
            bool isPlaceAny=false;
            set<pair<int,int> > exclude;exclude.clear();
            set<pair<int,int> > include;include.clear();
            for(set<pair<int,int> > ::iterator it=pool.begin(),tempIt;it!=pool.end();){
                tempIt=it;
                int id=it->second;
                bool leftAwkwardNess = IsAwkwardNess(it->second,left,graph);
                bool rightAwkwardNess = IsAwkwardNess(it->second,right,graph); //cout<<"["<<leftAwkwardNess<<" "<<rightAwkwardNess<<"]"<<endl;
                if(leftAwkwardNess && rightAwkwardNess){ //cout<<id<<" Impossibel"<<endl;
                    ans=false;     break;
                }
                else if(!leftAwkwardNess && rightAwkwardNess){
                    exclude.insert(*it);//pool.erase(*it);
                    left.insert(id); //cout<<id<<" placed at Left"<<endl;
                    isPlaceAny=true;   break;
                } else if(leftAwkwardNess && !rightAwkwardNess){
                    exclude.insert(*it);//pool.erase(*it);
                    right.insert(id); //cout<<id<<"placed at Right"<<endl;
                    isPlaceAny=true;      break;
                } else{
                    //just pull and push with current placed elements
                    exclude.insert(*it);//pool.erase(*it);
                    include.insert(make_pair(left.size()+right.size(),id));
                    //pool.insert(make_pair(left.size()+right.size(),id)); //cout<<id<<" Rearrange"<<endl;
                }
                it=++tempIt;
            }
            for(set<pair<int,int> >::iterator it=exclude.begin();it!=exclude.end();++it)
                pool.erase(*it);
            for(set<pair<int,int> >::iterator it=include.begin();it!=include.end();++it)
                pool.insert(*it);

            if(ans==false) break;//impossible configuration
            if(isPlaceAny==false){

                set<pair<int,int> > ::iterator it=pool.begin();  int id=it->second;
                pool.erase(*it); left.insert(id); //cout<<id<<"Forced placed at Left"<<endl;
            }
        }
        (left.size()+right.size()==n)?printf("YES\n"):printf("NO\n");
    } return 0;
}
