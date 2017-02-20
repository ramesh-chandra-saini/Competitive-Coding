
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> segTree(1000000,0);
ll update(ll ssx,ll ssy,ll ssz,ll sex,ll sey,ll sez,ll node,ll qx,ll qy,ll qz,ll val){
    ///cout<<ssx<<"  "<<ssy<<"  "<<ssz<<"  "<<sex<<"  "<<sey<<"  "<<sez<<"  "<<node<<"  "<<qx<<"  "<<qy<<"  "<<qz<<" "<<val<<endl;
    if(ssx>sex || ssy>sey || ssz>sez )
        return 0;
    if(ssx==sex && ssy==sey && ssz==sez)
        return (segTree[node]=segTree[node]+val);
    ll smx = (ssx+sex)/2;
    ll smy = (ssy+sey)/2;
    ll smz = (ssz+sez)/2;
    if(ssx<=qx && qx<=smx){
        if(ssy<=qy && qy<=smy){
            if(ssz<=qz && qz<=smz){
                update(ssx,ssy,ssz,smx,smy,smz,8*node+1,qx,qy,qz,val);
            }else{
                update(ssx,ssy,smz+1,smx,smy,sez,8*node+2,qx,qy,qz,val);
            }
        }else{
            if(ssz<=qz && qz<=smz){
                   update(ssx,smy+1,ssz,smx,sey,smz,8*node+3,qx,qy,qz,val);
            }else{
                    update(ssx,smy+1,smz+1,smx,sey,sez,8*node+4,qx,qy,qz,val);
            }
        }
    }else{
        if(ssy<=qy && qy<=smy){
            if(ssz<=qz && qz<=smz){
                update(smx+1,ssy,ssz,sex,smy,smz,8*node+5,qx,qy,qz,val);
            }else{
                update(smx+1,ssy,smz+1,sex,smy,sez,8*node+6,qx,qy,qz,val);
            }
        }else{
            if(ssz<=qz && qz<=smz){
                   update(smx+1,smy+1,ssz,sex,sey,smz,8*node+7,qx,qy,qz,val);
            }else{
                    update(smx+1,smy+1,smz+1,sex,sey,sez,8*node+8,qx,qy,qz,val);
            }
        }
    }
    return segTree[node] = (segTree[8*node+1]+segTree[8*node+2]+segTree[8*node+3]+segTree[8*node+4]+
                     segTree[8*node+5]+segTree[8*node+6]+segTree[8*node+7]+segTree[8*node+8]);
}

ll query(ll ssx,ll ssy,ll ssz,ll sex,ll sey,ll sez,ll node,ll qsx,ll qsy,ll qsz,ll qex, ll qey, ll qez){
    //cout<<ssx<<"  "<<ssy<<"  "<<ssz<<"  "<<sex<<"  "<<sey<<"  "<<sez<<"  "<<node<<"  "<<qsx<<"  "<<qsy<<"  "<<qsz<<"  "<<qex<<" "<<qey<<" "<<qez<<endl;
    if(ssx>sex || ssy>sey || ssz>sez || sex<qsx || qex<ssx || sey<qsy || qey<ssy|| sez<qsz || qez<ssz )
        return 0;
    if(qsx<=ssx && sex<=qex && qsy<=ssy && sey<=qey && qsz<=ssz && sex<=qez )
        return (segTree[node]);
    ll smx = (ssx+sex)/2;
    ll smy = (ssy+sey)/2;
    ll smz = (ssz+sez)/2;
    return query(ssx,ssy,ssz,smx,smy,smz,8*node+1,qsx,qsy,qsz,qex,qey,qez)+
           query(ssx,ssy,smz+1,smx,smy,sez,8*node+2,qsx,qsy,qsz,qex,qey,qez)+
            query(ssx,smy+1,ssz,smx,sey,smz,8*node+3,qsx,qsy,qsz,qex,qey,qez)+
            query(ssx,smy+1,smz+1,smx,sey,sez,8*node+4,qsx,qsy,qsz,qex,qey,qez)+
            query(smx+1,ssy,ssz,sex,smy,smz,8*node+5,qsx,qsy,qsz,qex,qey,qez)+
            query(smx+1,ssy,smz+1,sex,smy,sez,8*node+6,qsx,qsy,qsz,qex,qey,qez)+
            query(smx+1,smy+1,ssz,sex,sey,smz,8*node+7,qsx,qsy,qsz,qex,qey,qez)+
            query(smx+1,smy+1,smz+1,sex,sey,sez,8*node+8,qsx,qsy,qsz,qex,qey,qez);
}
int main(){
    ll n,q,total=0; cin >> n >> q;// cout<<n<<" "<<q<<endl;
    while(q--){
        ll t; cin >> t; //cout<<t<<endl;
        ll ax,ay,az,bx,by,bz,val;
        if(t==1){
            cin >> ax >> ay >> az >> val; //cout<<ax<<" "<<ay<<" "<<az<<" "<<val<<endl;
            total+=val;
            update(0,0,0,n,n,n,0,ax,ay,az,val);
        }else{
            cin >> ax >> ay >> az >> bx >> by >> bz; //cout<<ax<<" "<<ay<<" "<<az<<"    "<<bx<<" "<<by<<" "<<bz<<endl;
            cout<<total-query(0,0,0,n,n,n,0,ax,ay,az,bx,by,bz)<<endl;
        }
    }
}
