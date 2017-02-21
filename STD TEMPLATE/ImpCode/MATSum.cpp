#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> slgTree(10000000,0);
ll update(ll sfx,ll sfy,ll sfz,ll slx,ll sly,ll slz,ll node,ll qx,ll qy,ll qz,ll val,vector<ll>&segTree){
    if(sfx>slx || sfy>sly || sfz>slz )
        return 0;
    if(sfx==slx && sfy==sly && sfz==slz)
        return slgTree[node]=val;
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
    return slgTree[node] = (slgTree[8*node+1]+slgTree[8*node+2]+slgTree[8*node+3]+slgTree[8*node+4]+
                     slgTree[8*node+5]+slgTree[8*node+6]+slgTree[8*node+7]+slgTree[8*node+8]);
}

ll query(ll sfx,ll sfy,ll sfz,ll slx,ll sly,ll slz,ll node,ll qfx,ll qfy,ll qfz,ll qlx, ll qly, ll qlz){
   if(sfx>slx || sfy>sly || sfz>slz || slx<qfx || qlx<sfx || sly<qfy || qly<sfy|| slz<qfz || qlz<sfz )
        return 0;
    if(qfx<=sfx && slx<=qlx && qfy<=sfy && sly<=qly && qfz<=sfz && slx<=qlz )
        return (slgTree[node]);
    ll smx = (sfx+slx)/2;
    ll smy = (sfy+sly)/2;
    ll smz = (sfz+slz)/2;
    return query(sfx,sfy,sfz,smx,smy,smz,8*node+1,qfx,qfy,qfz,qlx,qly,qlz)+
           query(sfx,sfy,smz+1,smx,smy,slz,8*node+2,qfx,qfy,qfz,qlx,qly,qlz)+
            query(sfx,smy+1,sfz,smx,sly,smz,8*node+3,qfx,qfy,qfz,qlx,qly,qlz)+
            query(sfx,smy+1,smz+1,smx,sly,slz,8*node+4,qfx,qfy,qfz,qlx,qly,qlz)+
            query(smx+1,sfy,sfz,slx,smy,smz,8*node+5,qfx,qfy,qfz,qlx,qly,qlz)+
            query(smx+1,sfy,smz+1,slx,smy,slz,8*node+6,qfx,qfy,qfz,qlx,qly,qlz)+
            query(smx+1,smy+1,sfz,slx,sly,smz,8*node+7,qfx,qfy,qfz,qlx,qly,qlz)+
            query(smx+1,smy+1,smz+1,slx,sly,slz,8*node+8,qfx,qfy,qfz,qlx,qly,qlz);
}
int main(){
    ll n,q,total=0; cin >> n >> q;// cout<<n<<" "<<q<<endl;
    while(q--){
        ll type; cin >> type; //cout<<t<<endl;
        ll ax,ay,az,bx,by,bz,val;
        if(type==1){
            cin >> ax >> ay >> az >> val; //cout<<ax<<" "<<ay<<" "<<az<<" "<<val<<endl;
            update(0,0,0,n,n,n,0,ax,ay,az,val,segTree);
        }else{
            cin >> ax >> ay >> az >> bx >> by >> bz; //cout<<ax<<" "<<ay<<" "<<az<<"    "<<bx<<" "<<by<<" "<<bz<<endl;
            cout<<query(0,0,0,n,n,n,0,ax,ay,az,bx,by,bz,segTree)<<endl;
        }
    }
}
