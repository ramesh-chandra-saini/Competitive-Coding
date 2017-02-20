#include<bits/stdc++.h>
using namespace std;
int update(int sfx,int sfy, int slx, int sly,int node,int qx,int qy,int value,vector<int>&segTree){
    if(sfx>slx || sfy>sly )
        return 0;
    if(sfx==qx && slx==qx && sfy==qy && sly==qy)
        return segTree[node]=value;
    int smx = (sfx+slx)/2;
    int smy = (sfy+sly)/2;
    if(sfx<=qx && qx<=smx){
        if(sfy<=qy && qy<=smy){
            update(sfx,sfy,smx,smy,4*node+1,qx,qy,value,segTree);
        }else{
            update(sfx,smy+1,smx,sly,4*node+2,qx,qy,value,segTree);
        }
    }else{
        if(sfy<=qy && qy<=smy){
            update(smx+1,sfy,slx,smy,4*node+3,qx,qy,value,segTree);
        }else{
            update(smx+1,smy+1,slx,sly,4*node+4,qx,qy,value,segTree);
        }
    }
    return segTree[node]=(segTree[4*node+1]+segTree[4*node+2]+segTree[4*node+3]+segTree[4*node+4]);
}
int query(int sfx,int sfy, int slx, int sly,int node,int qfx,int qfy,int qlx, int qly,vector<int>&segTree){
    if( sfx>slx || sfy>sly || slx<qfx || qlx<sfx || sly<qfy || qly<sfy)
        return 0;
    if(qfx<=sfx && slx<=qlx && qfy<=sfy && sly<=qly)
        return segTree[node];
    int smx = (sfx+slx)/2;
    int smy = (sfy+sly)/2;
    return query(sfx,sfy,smx,smy,4*node+1,qfx,qfy,qlx,qly,segTree)+
        query(sfx,smy+1,smx,sly,4*node+2,qfx,qfy,qlx,qly,segTree)+
        query(smx+1,sfy,slx,smy,4*node+3,qfx,qfy,qlx,qly,segTree)+
        query(smx+1,smy+1,slx,sly,4*node+4,qfx,qfy,qlx,qly,segTree);
}
int main(){
    int t; cin >> t;while(t--){
        int n; cin >> n;
        vector<int> segTree((10*n*ceil(log2(n))),0);
        while(true){
            string type; cin >> type;
            if(type=="SET"){
                int x,y,num; cin >> x >> y >> num;
                update(0,0,n-1,n-1,0,x,y,num,segTree);
            }else if(type=="SUM"){
                int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
                cout<<query(0,0,n-1,n-1,0,x1,y1,x2,y2,segTree)<<endl;
            }else{
                break;
            } type.clear();
        }
        segTree.clear();
    } return 0;
}
