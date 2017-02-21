#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> segTree(10000000,0);
ll update(ll sfx,ll sfy,ll sfz,ll slx,ll sly,ll slz,ll node,ll qx,ll qy,ll qz,ll val,vector<ll>&segTree){
    if(sfx>slx || sfy>sly || sfz>slz)
        return 0;
    if(sfx==slx && sfy==sly && sfz==slz)
        return segTree[node]=val;
    ll smx = (sfx+slx)/2;
    ll smy = (sfy+sly)/2;
    ll smz = (sfz+slz)/2;
    if(sfx<=qx && qx<=smx)
        if(sfy<=qy && qy<=smy)
            if(sfz<=qz && qz<=smz)
                update(sfx,sfy,sfz,smx,smy,smz,8*node+1,qx,qy,qz,val,segTree);
            else
                update(sfx,sfy,smz+1,smx,smy,slz,8*node+2,qx,qy,qz,val,segTree);
        else
            if(sfz<=qz && qz<=smz)
                   update(sfx,smy+1,sfz,smx,sly,smz,8*node+3,qx,qy,qz,val,segTree);
            else
                    update(sfx,smy+1,smz+1,smx,sly,slz,8*node+4,qx,qy,qz,val,segTree);
    else
        if(sfy<=qy && qy<=smy)
            if(sfz<=qz && qz<=smz)
                update(smx+1,sfy,sfz,slx,smy,smz,8*node+5,qx,qy,qz,val,segTree);
            else
                update(smx+1,sfy,smz+1,slx,smy,slz,8*node+6,qx,qy,qz,val,segTree);
        else
            if(sfz<=qz && qz<=smz)
                   update(smx+1,smy+1,sfz,slx,sly,smz,8*node+7,qx,qy,qz,val,segTree);
            else
                    update(smx+1,smy+1,smz+1,slx,sly,slz,8*node+8,qx,qy,qz,val,segTree);
    return segTree[node] = (segTree[8*node+1]+segTree[8*node+2]+segTree[8*node+3]+segTree[8*node+4]+
                     segTree[8*node+5]+segTree[8*node+6]+segTree[8*node+7]+segTree[8*node+8]);
}
int depth=0;
ll query(ll sfx,ll sfy,ll sfz,ll slx,ll sly,ll slz,ll node,ll qfx,ll qfy,ll qfz,ll qlx, ll qly, ll qlz,vector<ll>&segTree){
    if(!depth--) return 0;
cout<<sfx<<"  "<<sfy<<"  "<<sfz<<"  "<<slx<<"  "<<sly<<"  "<<slz<<"  "<<node<<"  "<<qfx<<"  "<<qfy<<"  "<<qfz<<"  "<<qlx<<" "<<qly<<" "<<qlz<<endl;
   if(sfx>slx || sfy>sly || sfz>slz || slx<qfx || qlx<sfx || sly<qfy || qly<sfy|| slz<qfz || qlz<sfz )
        return 0;
    if(qfx<=sfx && slx<=qlx && qfy<=sfy && sly<=qly && qfz<=sfz && slx<=qlz )
        return (segTree[node]);
    ll smx = (sfx+slx)/2;
    ll smy = (sfy+sly)/2;
    ll smz = (sfz+slz)/2;
    return query(sfx,sfy,sfz,smx,smy,smz,8*node+1,qfx,qfy,qfz,qlx,qly,qlz,segTree)+
           query(sfx,sfy,smz+1,smx,smy,slz,8*node+2,qfx,qfy,qfz,qlx,qly,qlz,segTree)+
            query(sfx,smy+1,sfz,smx,sly,smz,8*node+3,qfx,qfy,qfz,qlx,qly,qlz,segTree)+
            query(sfx,smy+1,smz+1,smx,sly,slz,8*node+4,qfx,qfy,qfz,qlx,qly,qlz,segTree)+
            query(smx+1,sfy,sfz,slx,smy,smz,8*node+5,qfx,qfy,qfz,qlx,qly,qlz,segTree)+
            query(smx+1,sfy,smz+1,slx,smy,slz,8*node+6,qfx,qfy,qfz,qlx,qly,qlz,segTree)+
            query(smx+1,smy+1,sfz,slx,sly,smz,8*node+7,qfx,qfy,qfz,qlx,qly,qlz,segTree)+
            query(smx+1,smy+1,smz+1,slx,sly,slz,8*node+8,qfx,qfy,qfz,qlx,qly,qlz,segTree);
}
int main(){
    ll t,n; cin >> t >> n;
    while(t--){
        int segSize = 100*n*ceil(log2(n));
        vector<ll> segTree(segSize,0);
        while(true){
           string type; cin >> type;
            if(type=="SET"){
                int x,y,num; cin >> x >> y >> num;
                update(0,0,0,n,n,n,0,x,y,0,num,segTree);
            } else if(type=="SUM"){
                int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
                depth=10;
                cout<<query(0,0,0,n,n,n,0,x1,y1,0,x2,y2,0,segTree)<<endl;
            }else{
                break;
            }
        }

    }
}
