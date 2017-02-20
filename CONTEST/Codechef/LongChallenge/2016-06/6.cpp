#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[1005][1005][5];
ll Heap[1005],size=0;
 ll MAX[1005][1005];
ll Solve(ll i,ll j,ll R,ll C){
    ll mx=INT_MIN,sum=0;
    for(ll r=0;r<R;r++)
        for(ll c=0;c<C;c++)
            sum+=arr[i+r][j+c][0],mx=max(mx,arr[i+r][j+c][0]);//cout<<arr[i+r][j+c]<<" ";//cout<<endl<<(mx*R*C-sum)<<endl;
    return (mx*R*C-sum);
}
ll bruteForce(ll n,ll m, ll r, ll c){
    ll ans=INT_MAX;
        for(ll i=1;i<=n-r+1;i++)
            for(ll j=1;j<=m-c+1;j++)
                ans=min(ans,Solve(i,j,r,c));
    return ans;
}
void populateSum(ll n, ll m, ll r,ll c){
        //rowwise commulative
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                arr[i][j][1]=arr[i][j-1][1]+arr[i][j][0];
                         //for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++) cout<<arr[i][j][1]<<" "; cout<<endl;}
        //rowwise of segment length of r commulative
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<c;j++) arr[i][j][2]=arr[i][j][1];
            for(ll j=c;j<=m;j++)
                arr[i][j][2]=arr[i][j][1]-arr[i][j-c][1];}
                         //for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++) cout<<arr[i][j][2]<<" "; cout<<endl;}
        //column wise commulative
         for(ll j=1;j<=m;j++)
            for(ll i=1;i<=n;i++)
                arr[i][j][3]=arr[i-1][j][3]+arr[i][j][2];
                         //for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++) cout<<arr[i][j][3]<<" "; cout<<endl;}
         //sum of r*c matrix
         for(ll j=1;j<=m;j++){
            for(ll i=0;i<r;i++) arr[i][j][4]=arr[i][j][3];
            for(ll i=r;i<=n;i++)
                arr[i][j][4]=arr[i][j][3]-arr[i-r][j][3];}
                    //for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++) cout<<arr[i][j][4]<<" "; cout<<endl;}
}
void heapifyMin(ll Heap[],ll node,ll size){
    ll left=2*node+1;
    ll right=2*node+2;
    ll L=(left<size)? Heap[left]: INT_MIN;
    ll R=(right<size)? Heap[right]:INT_MIN;
    ll idx=left,value=L;
    if(R>L) idx=right,value=R;
    if(value<=Heap[node]);// no further heapify required
    else{
        swap(Heap[node],Heap[idx]);
        heapifyMin(Heap,idx,size);
    }
}
void deleteMax(){
    swap(Heap[0],Heap[size-1]); //swap with last entered element
    size--;//now delete last element
    heapifyMin(Heap,0,size);//now minHeapify root element to mantain maxHeap
}
void heapify(ll child){
    if(!child) return;//root case: reached till root
    ll parent=(child-1)/2;//get parent
    if(Heap[parent]>=Heap[child]) return;//no need of further heapify
    swap(Heap[parent],Heap[child]);//swap child and parent to suffice MaxHeap
    heapify(parent);//recure to next level
}
void insert(ll value){
        Heap[size++]=value;heapify(size-1);//insert new element and heapify
}
void createHeap(ll i,ll c){
    size=0;//flush old values from heap
    for(ll j=1;j<c;j++)//insert first (C-1) element
        insert(arr[i][j][0]);
}
void createHeap2(ll j,ll r){
    size=0; //flush old entry
    for(ll i=1;i<=r;i++)//insert first (R-1) element
        Heap[size++]=arr[i][j][0],heapify(size-1);//insert new element and heapify
}
void calMaxSeg(ll n,ll m,ll r,ll c,ll arrMax[1005][1005], ll arrMax2[1005][1005]){
 for(ll i=1;i<=n;i++){
            createHeap(i,c);//create Heap
            for(ll j=1;j<c;j++) arrMax[i][j]=max(arrMax[i][j],arr[i][j][0]);
            for(ll j=c;j<=m;j++){
                insert(arr[i][j][0]);//insert new element and heapify
                for(ll __i=0;__i<size;__i++) cout<<Heap[__i]<<" "; cout<<endl;
                arrMax[i][j]=Heap[0];//getMax
                deleteMax();//delete Max
            }
        }
        for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++) cout<<arrMax[i][j]<<" "; cout<<endl;}
        for(ll j=1;j<=m;j++){
            ll Heap[1005];
            createHeap2(j,r-1);
            for(ll i=1;i<r;i++) arrMax2[i][j]=max(arrMax2[i][j],arr[i][j][0]);
            for(ll i=r;i<=n;i++){
                  Heap[r-1]=arr[i][j][0],heapify(r-1);//insert new element and heapify
                    arrMax2[i][j]=Heap[0];
                deleteMax();
            }
        }
        for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++) cout<<arrMax2[i][j]<<" "; cout<<endl;}
}
void CalMaxSeg(ll n,ll m,ll r,ll c,ll arrMax[1005][1005], ll arrMax2[1005][1005]){
  //rowwise
    for(ll i=1;i<=n;i++){
        map<ll,ll> emap;
        set<ll>eset;
        set<ll> :: iterator it;
        for(ll j=1;j<c;j++){
            eset.insert((-1)*arr[i][j][0]);//to store in abs decreasing order
            emap[arr[i][j][0]]++;
        }
        for(ll j=c;j<=m;j++){
            eset.insert((-1)*arr[i][j][0]);
            emap[arr[i][j][0]]++;it=eset.begin();
            ll __max=*it*(-1); //get back max value
            arrMax[i][j]=__max;
            ll remEle=arr[i][j-c+1][0];//remove element which will now include to next window
            emap[remEle]--;
            if(emap[remEle]==0) eset.erase((-1)*remEle);
        }
        for(ll j=c-1;j>=1;j--) arrMax[i][j]=arrMax[i][j+1];//for first window
  }    //for(ll i=1;i<=n;i++){ for(ll j=1;j<=m;j++) cout<<arrMax[i][j]<<" "; cout<<endl;} cout<<endl;
   //colwise
    for(ll j=1;j<=m;j++){
        map<ll,ll> emap;
        set<ll>eset;
        set<ll> :: iterator it;
        for(ll i=1;i<r;i++){
            eset.insert((-1)*arr[i][j][0]);//to store in abs decreasing order
            emap[arr[i][j][0]]++;
        }
        for(ll i=r;i<=n;i++){
            eset.insert((-1)*arr[i][j][0]);
            emap[arr[i][j][0]]++; it=eset.begin();
            ll __max=*it*(-1);//get back max value
            arrMax2[i][j]=__max;
            ll remEle=arr[i-r+1][j][0];//remove element which will now include to next window
            emap[remEle]--;
            if(emap[remEle]==0) eset.erase((-1)*remEle);
        }
        for(ll i=r-1;i>=1;i--) arrMax2[i][j]=arrMax2[i+1][j];//for first window
    }
    //for(ll i=1;i<=n;i++){ for(ll j=1;j<=m;j++) cout<<arrMax2[i][j]<<" "; cout<<endl;} cout<<endl;
    memset(MAX,0,sizeof(MAX));
    /*for(ll i=r;i<=n;i++){
        for(ll j=c;j<=m;j++){
                //cout<<"("<<i<<","<<j<<") ";
                ll __max=INT_MIN;
                for(ll __i=i;__i>i-r;__i--){ //cout<<arrMax[__i][j]<<" ";
                    __max=max(__max,arrMax[__i][j]);
                } //cout<<" : ";
                for(ll __j=j;__j>j-c;__j--){ //cout<<arrMax2[i][__j]<<" ";
                    __max=max(__max,arrMax2[i][__j]);
                } //cout<<" :: "<<__max<<endl;
                MAX[i][j]=__max;
        }
    }
    */
    map<ll, map<ll,ll> > vmap;
    map<ll,set<ll> > vset;
    set<ll> :: iterator it;
    for(ll j=1;j<=m;j++){
        for(ll i=1;i<r;i++){
            vmap[i][arr[i][j][0]]++;
            vset[i].insert((-1)*arr[i][j][0]);
        }
    }
    map<ll,ll> rmap;
    set<ll> rset;
    set<ll>:: iterator rit;
    for(ll i=r;i<=n;i++){
        for(ll j=1;j<=m;j++){
             vmap[i][arr[i][j][0]]++;
             vset[i].insert((-1)*arr[i][j][0]);
            it=vset[i].begin();
            ll __max=*it*(-1);
            ll remEle=arr[i-r+1][j][0];
            vmap[i][remEle]--;
            if(vmap[i][remEle]==0) vset[i].erase(remEle);

            rmap[arr[i][j][0]]++;
            rset.insert((-1)*arr[i][j][0]);
            rit=rset.begin();
            ll __max2=*rit*(-1);
            if(j>=c){
                    ll remEle2=arr[i][j-c+1][0];
                    rmap[remEle2]--;
                    if(rmap[remEle2]==0) rset.erase(remEle2);
            }
            MAX[i][j]=max(__max2,__max);
        }
    }
    //for(ll i=1;i<=n;i++){ for(ll j=1;j<=m;j++) cout<<MAX[i][j]<<" "; cout<<endl;}
}
int main(){
    ll n,m; cin >> n >> m;
    memset(arr,0,sizeof(arr));
    for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)cin>> arr[i][j][0];
    ll q; cin >> q;
    while(q--){
        ll r,c; cin >> r >> c;
        //cout<<"BruteForce Ans : "<<bruteForce(n, m, r, c)<<endl;
        populateSum(n,m,r,c);//populate sum of r*c matrix
        ll arrMax[1005][1005]; memset(arrMax,0,sizeof(arrMax));  //now work on getting max of each matrix using max heap;
        ll arrMax2[1005][1005]; memset(arrMax2,0,sizeof(arrMax2));
        //calMaxSeg(n,m,r,c,arrMax,arrMax2);
        CalMaxSeg(n,m,r,c,arrMax,arrMax2);
       ll final_ans=INT_MAX;
        for(ll i=r;i<=n;i++)
            for(ll j=c;j<=m;j++)
                final_ans=min(final_ans,(MAX[i][j]*r*c-arr[i][j][4]));
        cout<<final_ans<<endl;
    }
    return 0;
}
