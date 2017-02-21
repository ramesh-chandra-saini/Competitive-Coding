#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool safe(vector<vector<int> >&A,int R,int C){
    /*for(int i=1;i<=R;i++,cout<<endl)
        for(int j=1;j<=C;j++)
            cout<<A[i][j]<<" ";*/
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(A[i][j]==1&& ( (A[i][j-1]==1 &&A[i][j+1]==1) || (A[i-1][j]==1 && A[i+1][j]==1)))
                return false;

    return true;
}
/*void solve(int i,int j,int R,int C,vector<vector<int> >mat){

    if((i==R+1 && j==C) || (i==R && j==C+1)){
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            cout<<mat[i][j]<<" ";cout<<endl;
        if(!safe(mat,R,C)) return ;
        int ct =0;
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                ct+=mat[i][j];
        ans=max(ans,ct);
        return ;
    }

    if(i>R || j>C)return;
    mat[i][j]=1;
    solve(i+1,j,R,C,mat);
    solve(i,j+1,R,C,mat);
    mat[i][j]=0;
    solve(i+1,j,R,C,mat);
    solve(i,j+1,R,C,mat);

}*/
ll sum(vector<vector<int> > &A,int R,int C,int sum=0){
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            sum+=A[i][j];
    return sum;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t; cin >> t; for(int T=1;T<=t;T++){
        int R,C; cin >> R >> C;
        vector<vector<int> > mat(R+2,vector<int>(C+2,0));
        ll N = 1LL<<(R*C);
        ll ans =0;
        for(ll i=1;i<N;i++){
            ll temp = i;
            for(int k=1;k<=R;k++)
                    for(int l=1;l<=C;l++,temp/=2LL)
                        mat[k][l]=temp%2LL;
            /*for(int k=1;k<=R;k++,cout<<endl)
                for(int l=1;l<=C;l++)
                    cout<<mat[k][l]<<" "; cout<<endl;*/
            if(safe(mat,R,C))
                ans = max(ans,sum(mat,R,C));
        }
        cout<<"Case #"<<T<<" "<<ans<<endl;
    } return 0;
}
