#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 10000000
vector<ll> segTree(SIZE,0);
ll update(ll sfx,ll sfy,ll sfz,ll slx,ll sly,ll slz,ll node,ll qx,ll qy,ll qz,ll val){
	//if(8+8*node>=SIZE) return 0;
    if(sfx>slx || sfy>sly || sfz>slz )
        return 0;
    if(sfx==slx && sfy==sly && sfz==slz)
        return segTree[node]=val;
    ll smx = (sfx+slx)/2;
    ll smy = (sfy+sly)/2;
    ll smz = (sfz+slz)/2;
    if(sfx<=qx && qx<=smx)
        if(sfy<=qy && qy<=smy)
            if(sfz<=qz && qz<=smz)
                update(sfx,sfy,sfz,smx,smy,smz,8*node+1,qx,qy,qz,val);
            else
                update(sfx,sfy,smz+1,smx,smy,slz,8*node+2,qx,qy,qz,val);
        else
            if(sfz<=qz && qz<=smz)
                   update(sfx,smy+1,sfz,smx,sly,smz,8*node+3,qx,qy,qz,val);
            else
                    update(sfx,smy+1,smz+1,smx,sly,slz,8*node+4,qx,qy,qz,val);
    else
        if(sfy<=qy && qy<=smy)
            if(sfz<=qz && qz<=smz)
                update(smx+1,sfy,sfz,slx,smy,smz,8*node+5,qx,qy,qz,val);
            else
                update(smx+1,sfy,smz+1,slx,smy,slz,8*node+6,qx,qy,qz,val);
        else
            if(sfz<=qz && qz<=smz)
                   update(smx+1,smy+1,sfz,slx,sly,smz,8*node+7,qx,qy,qz,val);
            else
                    update(smx+1,smy+1,smz+1,slx,sly,slz,8*node+8,qx,qy,qz,val);

    return segTree[node] = max(segTree[8*node+1],max(segTree[8*node+2],max(segTree[8*node+3],max(segTree[8*node+4],max(
                     segTree[8*node+5],max(segTree[8*node+6],max(segTree[8*node+7],segTree[8*node+8])))))));
}
ll query(ll sfx,ll sfy,ll sfz,ll slx,ll sly,ll slz,ll node,ll qfx,ll qfy,ll qfz,ll qlx, ll qly, ll qlz){
  //if(8+8*node>=SIZE) return 0;
   if(sfx>slx || sfy>sly || sfz>slz || slx<qfx || qlx<sfx || sly<qfy || qly<sfy|| slz<qfz || qlz<sfz )
        return 0;
    if(qfx<=sfx && slx<=qlx && qfy<=sfy && sly<=qly && qfz<=sfz && slz<=qlz )
        return (segTree[node]);
    ll smx = (sfx+slx)/2;
    ll smy = (sfy+sly)/2;
    ll smz = (sfz+slz)/2;
    return max(query(sfx,sfy,sfz,smx,smy,smz,8*node+1,qfx,qfy,qfz,qlx,qly,qlz),
           max(query(sfx,sfy,smz+1,smx,smy,slz,8*node+2,qfx,qfy,qfz,qlx,qly,qlz),
           max(query(sfx,smy+1,sfz,smx,sly,smz,8*node+3,qfx,qfy,qfz,qlx,qly,qlz),
           max(query(sfx,smy+1,smz+1,smx,sly,slz,8*node+4,qfx,qfy,qfz,qlx,qly,qlz),
           max(query(smx+1,sfy,sfz,slx,smy,smz,8*node+5,qfx,qfy,qfz,qlx,qly,qlz),
           max(query(smx+1,sfy,smz+1,slx,smy,slz,8*node+6,qfx,qfy,qfz,qlx,qly,qlz),
           max(query(smx+1,smy+1,sfz,slx,sly,smz,8*node+7,qfx,qfy,qfz,qlx,qly,qlz),
            query(smx+1,smy+1,smz+1,slx,sly,slz,8*node+8,qfx,qfy,qfz,qlx,qly,qlz))))))));
}
int main(){
    ll q; cin >> q; while(q--){
        ll n; cin >> n;
        vector<ll> arr(n*n*n+1); for(int i=1;i<=n*n*n;i++) cin >> arr[i];
        ll mat[n+1][n+1][n+1];
        for(ll x=1;x<=n;x++){
            for(ll y=1;y<=n;y++){
                for(ll z=1;z<=n;z++){
                    mat[x][y][z]=arr[(x-1)*n*n+(y-1)*n+z];
                    update(1LL,1LL,1LL,n,n,n,0LL,x,y,z,mat[x][y][z]);
                    //cout<<mat[x][y][z]<<" ";
                } //cout<<endl;
            }//cout<<endl;
        } //cout<<endl;
        for(ll k=1;k<=n;k++){
            ll ct=0;
            for(ll x=1;x<=n-k+1;x++)
                for(ll y=1;y<=n-k+1;y++)
                    for(ll z=1;z<=n-k+1;z++){
                        ll mx = query(1,1,1,n,n,n,0,x,y,z,x+k-1,y+k-1,z+k-1);
                        //cout<<"["<<x<<" "<<y<<" "<<z<<"]--> ["<<x+k-1<<" "<<y+k-1<<" "<<z+k-1<<"]  "<<mx<<endl;
                        ct+=(k==mx);
                    }
            cout<<ct<<" ";
        } cout<<endl;
    } return 0;
}
