#include<bits/stdc++.h>
using namespace std;
bool NOT_OUT(int i,int j,int row,int col){

    if(i<0 || j<0 || i>=row || j>=col) return false;
    return true;
}
int main(){

    int row,col;
    cin >> row >> col;

    int arr[row+1][col+1];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> arr[i][j];
        }
    }
/*
    for(int i=0;i<row;cout<<endl,i++){

        for(int j=0;j<col;j++){
            cout<< arr[i][j] << " ";
        }
    }
    */
    if(row==1){
        for(int j=0;j<col;j++)
            cout<<arr[0][j]<<" ";
        cout<<endl;
    }
    else if(col==1){
        for(int i=0;i<row;i++)
            cout<<arr[i][0]<<" ";
        cout<<endl;
    }else{
        cout<<arr[0][0]<<" ";
        bool flag=false;
        ///flag == false go down (+1,-1) else go up(-1,+1)
        int ct=row*col;

        int i=0,j=1; ct--;

        while(ct){

            if(flag==false){

                while(NOT_OUT(i,j,row,col)){

                    cout<<arr[i][j]<<" ";
                    i+=1,j+=-1;
                    ct--;
                }
                j++,i+=-1;
                if(i+1<row) i++;
                else j++;
                flag=true;
            }
            else{

                while(NOT_OUT(i,j,row,col)){

                    cout<<arr[i][j]<<" ";
                    i+=-1,j+=1;
                    ct--;
                }
                i+=1,j-=1;
                if(j+1<col) j++;
                else i++;
            }
            flag=false;
        }
        cout<<endl;
    }
    return 0;
}
