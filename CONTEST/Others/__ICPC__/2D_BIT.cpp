#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll matrix[1025][1025];
ll BIT[1025][1025];
void update(int x,int y,int n,int val){
    for(int i=x;i<=n;i+=(i&-i))
        for(int j=y;j<=n;j+=(j&-j))
                BIT[i][j]+=val;
}
ll query(int x,int y,ll sum=0){
    for(int i=x;i>0;i-=(i&-i))
        for(int j=y;j>0;j-=(j&-j))
                sum+=BIT[i][j];
    return sum;
}
ll getSum(int x,int y,int X,int Y){
    return query(X,Y)-query(x-1,Y)-query(X,y-1)+query(x-1,y-1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,i,j,val,l,r,L,R; cin >> t;
    char s[4];
    while(t--){
        cin >> n;
        memset(matrix,0,sizeof(matrix));
        memset(BIT,0,sizeof(BIT));
        int q; cin >> q;
        while(q--){
            int type; cin >> type;
            if(type==1){
                cin >> i >> j >> val;
                i++,j++; //change 0-based index to 1-based index
                update(i,j,n,-matrix[i][j]+val);
                matrix[i][j]=val;
            }else {
                cin >> l >> r >> L >> R;
                l++,r++,L++,R++; //change 0-based index to 1-based index
                cout<<getSum(l,r,L,R)<<endl;
            }
        }

    }
    return 0;
}
