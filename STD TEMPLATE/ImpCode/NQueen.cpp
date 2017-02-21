/*
    N Queen Problem
    concept : Backtracking
    lenght code....but easy to understand.....:)
*/
#include<bits/stdc++.h>
using namespace std;
bool checkDiagonal(int row,int col,int n,int x,int y,vector<vector<int> >&arr){
   for(int i=row,j=col;i<n && i>=0 && j<n && j>=0;i+=x,j+=y)
        if(arr[i][j])
            return false;
    return true;
}
bool isSafe(int row,int col,int n, vector<vector<int> >&arr){
    for(int i=0;i<n;i++) //check vertical
        if(arr[i][col])
            return false;
    for(int j=0;j<n;j++) //check horzontal
        if(arr[row][j])
            return false;
    //check diagonal
    if(!checkDiagonal(row,col,n,-1,-1,arr))
        return false;
    if(!checkDiagonal(row,col,n,-1,+1,arr))
        return false;
    if(!checkDiagonal(row,col,n,+1,-1,arr))
        return false;
    if(!checkDiagonal(row,col,n,+1,+1,arr))
        return false;
    return true;
}
bool solve(int row,int n,vector<vector<int> >&arr){
    if(row==n)//base case : covered all rows
        return true;
    for(int col=0;col<n;col++)
            //check is this position safe or not
            if(isSafe(row,col,n,arr)){
                arr[row][col]=1; //place queen
                if(solve(row+1,n,arr)) //go for next row(Queen placement)
                    return true;
                arr[row][col]=0;   //remove queen
            }
    return false;
}
int main(){
    int n; cin >> n;
    vector<vector<int> >arr(n,vector<int>(n,0));
    //Solve N Queen Problem
    if(solve(0,n,arr)){
        for(int i=0;i<n;i++,cout<<endl)
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<"   ";
    }else
        printf("Solution does not exist\n");

    return 0;
}
