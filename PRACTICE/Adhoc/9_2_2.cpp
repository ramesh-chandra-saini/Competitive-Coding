/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
int path[26000];
int pathSize=0;
void printVec(int vec[],int size){
    for(int i=0;i<size;i++) printf("%d ",vec[i]); printf("\n");
}
void copyVec(int source[],int destination[],int size){
    for(int i=0;i<size;i++) destination[i]=source[i];
}
void getPath(vector<set<int>>&tree,bool visit[],int curr,int target,int currPath[],int currPathSize){
    if(currPath[currPathSize-1]==target) { copyVec(currPath,path,currPathSize); pathSize=currPathSize; return;}
    for(int i=0;i<tree[curr].size();i++)
        if(!visit[tree[curr][i]]){
            visit[tree[curr][i]]=true,currPath[currPathSize++]=tree[curr][i];
            getPath(tree,visit,tree[curr][i],target,currPath,currPathSize);
            currPathSize--;
        } return;
}
void reversePath(int path[], int weight[],int size){
    for(int i=0;i<size/2;i++) swap(weight[path[i]],weight[path[size-1-i]]);
}

int weight[26000];
bool visit[26000];
int currPath[26000],A[26000],B[26000],copyVector[26000];
int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
    vector<vector<int> >tree(n+1,vector<int>());
    for(int i=1,x,y;i<=n-1;i++)scanf("%d%d",&x,&y),tree[x].push_back(y),tree[y].push_back(x);
   // for(int i=0;i<tree.size();i++){cout<<i<<" --> "; for(int j=0;j<tree[i].size();j++) cout<<tree[i][j]<<" "; cout<<endl;}
    while(q--){
        int choice,u,v,ul,ur,vl,vr,currPathSize; scanf("%d",&choice);
        bool flag=true;
        switch(choice){
            case 1:
                currPathSize=0,pathSize=0,memset(visit,false,sizeof(visit));
                scanf("%d%d",&u,&v); visit[u]=true,currPath[currPathSize++]=u;
                getPath(tree,visit,u,v,currPath,currPathSize);
               // cout<<"Path["<<u<<"<-->"<<v<<"] ";for(int i=0;i<path.size();i++) cout<<path[i]<<" "; cout<<endl;
                reversePath(path,weight,pathSize);
            break;
            case 2:
                scanf("%d%d%d%d",&ul,&ur,&vl,&vr);
                currPathSize=0,pathSize=0,memset(visit,false,sizeof(visit));
                u=ul,v=ur; visit[u]=true,currPath[currPathSize++]=u;
                getPath(tree,visit,u,v,currPath,currPathSize);
                //cout<<"Path["<<u<<"<-->"<<v<<"] ";for(int i=0;i<path.size();i++) cout<<path[i]<<" "; cout<<endl;
                for(int i=0;i<pathSize;i++) A[i]=weight[path[i]];
                currPathSize=0,pathSize=0,memset(visit,false,sizeof(visit));
                u=vl,v=vr; visit[u]=true,currPath[currPathSize++]=u;
                getPath(tree,visit,u,v,currPath,currPathSize);
                //cout<<"Path["<<u<<"<-->"<<v<<"] ";for(int i=0;i<path.size();i++) cout<<path[i]<<" "; cout<<endl;
                for(int i=0;i<pathSize;i++) B[i]=weight[path[i]];
                for(int i=0;i<pathSize;i++) flag=(A[i]!=B[i])?false:flag;
                (flag)?printf("Yes\n"):printf("No\n");
            break;
            case 3:
                scanf("%d%d%d%d",&ul,&ur,&vl,&vr);
                currPathSize=0,pathSize=0,memset(visit,false,sizeof(visit));
                u=ul,v=ur; visit[u]=true,currPath[currPathSize++]=u;
                getPath(tree,visit,u,v,currPath,currPathSize);
                //cout<<"Path["<<u<<"<-->"<<v<<"] ";for(int i=0;i<path.size();i++) cout<<path[i]<<" "; cout<<endl;
                for(int i=0;i<pathSize;i++)A[i]=path[i],copyVector[A[i]]=weight[A[i]];
                //copyVec(path,A,pathSize);
                currPathSize=0,pathSize=0,memset(visit,false,sizeof(visit));
                u=vl,v=vr; visit[u]=true,currPath[currPathSize++]=u;
                getPath(tree,visit,u,v,currPath,currPathSize);
                //cout<<"Path["<<u<<"<-->"<<v<<"] ";for(int i=0;i<path.size();i++) cout<<path[i]<<" "; cout<<endl;
                //copyVec(path,B,pathSize);copyVec(weight,copyVector,n);
                for(int i=0;i<pathSize;i++) weight[path[i]]=copyVector[A[i]];
            break;
        }
    }return 0;
}
