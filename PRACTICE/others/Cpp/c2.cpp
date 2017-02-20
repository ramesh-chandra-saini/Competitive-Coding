#include<bits/stdc++.h>
using namespace std;

bool notOut(int i,int j,int row,int col){
    if( i>=0 && i<row && j>=0 && j<col) return true;
    return false;
}
bool checkResult(char v[][20],int N,int K){
/*
  for(int __i=0;__i<N;__i++)
                cout<<v[__i]<<endl;
                      cout<<endl;
*/
    //row-wise
    for(int i=0;i<N;i++){
        int count=0;
        for(int j=0;j<N;j++){
                if(v[i][j]=='X') {count++; if(count>=K) return true;}
                else count=0;
        }
    }

    //column-wise
    for(int i=0;i<N;i++){
        int count=0;
        for(int j=0;j<N;j++){
                if(v[j][i]=='X') {count++; if(count>=K) return true;}
                else count=0;
        }
    }

    //Diagonals
    //col-wise
    for(int j=0;j<N;j++){

        int x=0,y=j,count=0;
        while(notOut(x,y,N,N)){
            if(v[x][y]=='X') {count++; if(count>=K) return true;}
            else count=0;
            x++,y--;
        }
    }
    //row-wise
    for(int i=0;i<N;i++){

        int x=i,y=N-1,count=0;
        while(notOut(x,y,N,N)){
           if(v[x][y]=='X') {count++; if(count>=K) return true;}
            else count=0;
            x++,y--;
        }
    }
    //row-wise
    for(int i=N-1;i>=0;i--){
        int x=i,y=0,count=0;
        while(notOut(x,y,N,N)){
           if(v[x][y]=='X') {count++; if(count>=K) return true;}
            else count=0;
            x++,y++;
        }
    }
    //col-wise
    for(int j=0;j<N;j++){

        int x=0,y=j,count=0;
        while(notOut(x,y,N,N)){
            if(v[x][y]=='X') {count++; if(count>=K) return true;}
            else count=0;
            x++,y++;
        }
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        char v[20][20];
        for(int i=0;i<n;i++)
            cin >> v[i];
            //cout<<endl;
        bool ans=false;
        for(int i=0;i<n && ans==false;i++){
            for(int j=0;j<n && ans==false;j++){

                if(v[i][j]=='.'){
                    v[i][j]='X';
                    ans=checkResult(v,n,k);
                    v[i][j]='.';
                }
            }
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
