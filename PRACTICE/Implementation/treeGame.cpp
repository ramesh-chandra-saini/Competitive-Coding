#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
       vector<vector<int> > adjList(n+1,vector<int>()); //for(int i =0;i<=n;i++) adjList[i].clear();
        for(int i=0,x,y;i<n-1;i++){
            cin >> x >> y ;   //cout<<x<<" -> "<<y<<endl;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        //for(int i=1;i<=n;i++,cout<<endl) { cout<<i<<"";for(int j=0;j<adjList[i].size();j++) cout<<"-->"<<adjList[i][j]<<" ";}
       vector<int> Label(n+1,0); int label=-1;//memset(Label,0,sizeof(Label));
        vector<bool> visit(n+1,false);visit[0]=true; // memset(visit,false,sizeof(visit));
        vector<int> root; root.clear(); root.push_back(1); //visit[1] = true; //take root as 1;
        vector<pair<int,int> > nodeLabel; nodeLabel.clear();
         vector<vector<int> > LabelWise; LabelWise.clear();
       while(root.size()){
            ++label;
            vector<int> child; child.clear(); vector<int> labelRoot; labelRoot.clear();
            for(int i=0;i<root.size();i++){
                int node = root[i];  //cout<<node<<"("<<label<<") ";
                if(visit[node]==false){ ///cout<<node<<"("<<label<<") ";
                        Label[node]=label; visit[node]=true;labelRoot.push_back(node);
                        for(int j=0;j<adjList[node].size();j++){
                            if(visit[adjList[node][j]]==false) child.push_back(adjList[node][j]);
                        }
                }
            }// cout<<endl;
            if(labelRoot.size()) LabelWise.push_back(labelRoot);
            root=child;
        }
        bool alice=true;
        int ans=0;
        int L=0,R=LabelWise.size()-1,idx2=LabelWise[R].size()-1;
        while(L<=R){
            ++ans;
            if(alice){ //cout<<"Alice : "; for(int i=0;i<LabelWise[L].size();i++) cout<<LabelWise[L][i]<<" "; cout<<endl;
             //LabelWise.erase(LabelWise.begin());
             L++;
             }
            else{
                idx2--;
                if(idx2<0) { R--;idx2=LabelWise[R].size()-1; }
            }
            alice =true ^ alice;
        }
        cout<<ans<<endl;
    }
    return 0;
}
