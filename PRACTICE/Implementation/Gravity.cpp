#include<bits/stdc++.h>
using namespace std;
void BFS(){

}
int main(){
    int n; cin >> n;
    vector<set<int> >adjList(n+1,set<int>());
    for(int k=1,x;k<n;k++){
        cin >> x;
       int parent = x;
       int child = k+1;
       adjList[parent].insert(child);
    }
    vector<int> levelHolder(n+1,0);



    int parent=0;
    for(vector<set<int> >::iterator it = adjList.begin();it!=adjList.end();++it){
        cout<<parent<<" --> ";        parent++;

        for(set<int>::iterator sit = (*it).begin();sit!=(*it).end();++sit){
            cout<<*sit<<" ";
        }
        cout<<endl;
    }
}
