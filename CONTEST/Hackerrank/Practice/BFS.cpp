/*

    AUTHOR : RAMESH CHANDRA

    BREADTH FIRST SEARCH
*/

#include<bits/stdc++.h>
using namespace std;

int main(){



    int N,M;//N: number of nodes, M number of edges

    cin >> N >> M;
    int tree[N+1][N+1];

    memset(tree,0,sizeof(tree));
/*
    for(int i=0;i<=N;i++){

        for(int j=0;j<=N;j++)
            cout<< tree[i][j]<<" ";
        cout<<endl;
    }
*/
    while(M--){

        int x,y;

        cin >> x >> y;

        tree[x][y]=tree[y][x]=1;
    }

    /***********************************BFS*************************/


    int S; //Source


    cin >> S;

    queue<int> Q;

    vector<bool> visit(N+1,false);

    Q.push(S); //push source into queue
    Q.push(-1); //push level diffrenciator{detector}

    visit[S]=true;

    int dist=6;
    vector<int> D(N+1,-1);
    while(Q.size()>1){ //if queue contains atleast one nodes other than level detector


        int source=Q.front(); Q.pop();

        if(source==-1){ //this show one level is over

            cout<<endl;
            dist+=6;
            //whaterver you have in queue are in one level
            Q.push(-1);//push level diffrenciator{detector}
        }
        else{  //remove first node and print all child of it


            for(int i=0;i<=N;i++){

                if(!visit[i] && tree[source][i]==1){

                    cout<<source<<" --> "<<i<<"  "<<dist<<endl;
                    D[i]=dist;
                    visit[i]=true;
                    Q.push(i);//push child of source for further level
                }
            }
        }
    }

    for(int i=1;i<S;i++) cout<<D[i]<<" ";
    for(int i=S+1;i<=N;i++) cout<<D[i]<<" "; cout<<endl;
    return 0;
}
