#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll BIT[102][102][102];

void update(int x,int y,int z,int n,int val){
    for(int i=x;i<=n;i+=(i&-i))
        for(int j=y;j<=n;j+=(j&-j))
            for(int k=z;k<=n;k+=(k&-k))
                BIT[i][j][k]+=val;
}
ll query(int x,int y,int z,ll sum=0){
    for(int i=x;i>0;i-=(i&-i))
        for(int j=y;j>0;j-=(j&-j))
            for(int k=z;k>0;k-=(k&-k))
                sum+=BIT[i][j][k];
    return sum;
}
ll getSum(int x,int y,int z,int X,int Y,int Z){
    return query(X,Y,Z)-query(x-1,Y,Z)-query(X,y-1,Z)-query(X,Y,z-1)+query(x-1,y-1,Z)+query(X,y-1,z-1)+query(x-1,Y,z-1)-query(x-1,y-1,z-1);
}
int main(){
    int n,q;cin >> n >> q;
    ll total=0LL;
    while(q--){
        int type; cin >> type;
        if(type==1){
            int x,y,z,val; cin >> x >> y >> z >> val;
            total+=val;
            x++,y++,z++;//change 0-based index to 1-based index
            update(x,y,z,n+1,val);
        }else{
            int x,y,z,X,Y,Z; cin >> x >> y >> z >> X >> Y >> Z;
            x++,y++,z++,X++,Y++,Z++; //change 0-based index to 1-based index
            cout<<total-getSum(x,y,z,X,Y,Z)<<endl;
        }
    }
}
