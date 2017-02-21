#include<bits/stdc++.h>
using namespace std;
void print(vector<set<int> > ls,int n){
    for(int i=1;i<=n;i++){
            cout<<i<<" ---> ";
            for(set<int>::iterator j=ls[i].begin();j!=ls[i].end();j++){
                cout<<*j<<" ";
            }
            cout<<endl;
        }
}
void print(vector<vector<int> > vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        } cout<<endl;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int q; cin >> q;
    while(q--){
        int n,m; cin >> n >> m;
        vector<set<int> > DS(n+1,set<int>());// i  --> j
        vector<set<int> > ds(n+1,set<int>());// j  --> i
        for(int i=1;i<=n;i++){
            int size ; cin >> size;
            for(int j=0;j<size;j++){
                int x; cin >> x;
                DS[i].insert(x);
                ds[x].insert(i);
            }
        } //  print(DS,n); print(ds,n);
        set<int> M;
        for(int i=0,x;i<m;i++)
            cin >> x,M.insert(x);

        vector<bool> visited(n+1,false);
        bool isPossible = true;

        vector<vector<int> > process;process.clear();
        for(int i=1;i<=n;i++){
            if(DS[i].size()==0 && visited[i]==false){

                set<int> buff; buff.clear();
                vector<int> curr;curr.clear();
                buff.insert(i);
                do{
                    set<int>next_buff; next_buff.clear();
                    for(set<int>::iterator it = buff.begin();it!=buff.end();++it){
                        int node = *it;
                        if(visited[node]==false && DS[node].size()==0){
                            visited[node]=true;
                            curr.push_back(node);
                            for(set<int> ::iterator j=ds[node].begin();j!=ds[node].end();j++){
                                next_buff.insert(*j);
                                DS[*j].erase(node);
                            }
                        }
                    }
                    buff = next_buff;
                }while(buff.size());
                   // reverse(curr.begin(),curr.end());
                    process.push_back(curr);
            }
        }     print(process);
        vector<vector<int> > final_process; final_process.clear();
        int mn = 0;
        for(int i=0;i<process.size();i++){
            bool check = false;
            for(int j=process[i].size()-1;j>=0;j--){
                int node = process[i][j];
                if(check==false){
                    if(M.find(node)==M.end()){
                        process[i].pop_back();
                    }else{
                        check = true;
                        M.erase(node);
                    }
                }else{
                    if(M.find(node)!=M.end()){
                        check = true;
                        M.erase(node);
                    }
                }
            }
            if(check==true){
                mn+=process[i].size();
                final_process.push_back(process[i]);
            }
        } print(final_process);
        cout<<mn<<endl;
        while(mn--){
            int __mn = INT_MAX;
            int id = 0;
            for(int i=0;i<final_process.size();i++){
                if(__mn>final_process[i][0]){
                    __mn = final_process[i][0];
                    id = i;
                }
            }
            cout<<__mn<<" ";
            final_process[id].erase(final_process[id].begin());
            if(final_process[id].empty()){
                final_process.erase(final_process.begin()+id);
            }
        } cout<<endl;
    }
    return 0;
}
