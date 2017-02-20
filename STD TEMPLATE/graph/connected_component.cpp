#include<bits/stdc++.h>
using namespace std;

void dfsrec(vector<vector<int > >&A,int source,bool *visit,map<int,int> &M){

    for(int i=1;i<A[source].size();++i){

        if(!visit[A[source][i]]){

            visit[A[source][i]]=true;
            dfsrec(A,M[A[source][i]],visit,M);
        }
    }
}
int block(vector<string > &A){

    int n=A.size();
    int m=A[0].length();

     string bottom(m+2,'O');  A.push_back(bottom);

     string top(m+2,'O'); A.insert(A.begin(),top);


    for(int i=1;i<=n;i++ ){

        A[i].push_back('O');
        A[i].insert(A[i].begin(),'O');
    }

   // for(int i=0;i<=n+1;i++) cout<<A[i]<<endl;

    vector<vector<int> > adjList;adjList.clear();

    map<int,int> M; M.clear();
    int node=1;
    int p=0;
    vector<int> link;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            if(A[i][j]=='X'){

                link.clear();link.push_back(node);
                M[node]=p; p++;
                if(A[i-1][j]=='X') link.push_back(node-m);
                if(A[i][j-1]=='X') link.push_back(node-1);
                if(A[i][j+1]=='X') link.push_back(node+1);
                if(A[i+1][j]=='X') link.push_back(node+m);
                adjList.push_back(link);
            }
            node++;
        }
    }

    int sz=adjList.size();
    for(int i=0;i<sz;i++){

        int sz2=adjList[i].size();
        cout<<adjList[i][0]<<" : ";
        for(int j=1;j<sz2;j++){

            cout<<" -> "<<adjList[i][j];
        }
        cout<<endl;
    }
    int ct=0;
    int _sz=(n+2)*(m+2);
    bool *visit=(bool*)malloc(_sz*sizeof(bool));


    for(int i=0;i<_sz;visit[i++]=false);

    for(int i=0;i<sz;i++){

        if(!visit[adjList[i][0]]){
            ct++;
            visit[adjList[i][0]]=true;
            dfsrec(adjList,i,visit,M);
        }
    }

    return ct;
}

int main(){

    int n;

    cin>>n;

    vector<string> vec; vec.clear();
    string str;
    while(n--){

        cin>>str;
        vec.push_back(str);
    }
    cout<<"Ans : "<<block(vec)<<endl;
    return 0;
}
