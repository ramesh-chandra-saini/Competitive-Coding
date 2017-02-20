/*
    Author : Ramesh Chandra
    National Institute Of Technology Karnataka Surathkal
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define gc getchar_unlocked
typedef long long int INT;
inline void read(INT &x){
	register INT c = gc();x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
inline void write(long long int a){
    char snum[35];  int i = 0;
    do{
        snum[i++] = a%10 +48;
        a = a/10;
    }while(a!= 0);--i;
    while(i>=0) putchar_unlocked(snum[i--]); putchar_unlocked('\n');
}
ll L =0;
ll NODE(ll N,bool RealLeaf[],vector<vector<ll> >&graph,ll __N,ll prev,ll curr){

    if(N==RealLeaf[N]) return 0LL;
    ll ans=0,ans2=0;
    //cout<<N;
    for(ll i=1;i<=__N;i++){
             //if(L ==0) break;else L--;
        if(graph[N][i] && i!=prev){ //prev=curr;curr=i;
        ans2=graph[N][i]; //cout<<"-->"<<i<<" ";
        ans2+=NODE(i,RealLeaf,graph,__N,curr,i);
        ans=max(ans,ans2);
        //cout<<"("<<N<<" "<<i<<")"<<"\t";
        }
    } //cout<<"("<<ans<<")"<<" | ";
    return ans;
}
int main(){
    ll t;read(t);// cin >> t;
    while(t--){
        ll n; read(n);// cin >> n; // number of nodes
        ll hash[n+1],tree[n+1][2],Leaf[n+1],Releaf[n+1],L=0,R=0;bool RealLeaf[n+1];
        for(ll i=0;i<=n;i++){RealLeaf[i]=false;hash[i]=tree[i][0]=tree[i][1]=0LL;}//memset(tree,0,sizeof(tree)); memset(hash,0,sizeof(hash));//storing frequency of all nodes, which will help to know which is leaf node
        tree[1][0] = 0; tree[1][1] = 0;
        for(ll i=0,x,y,w,temp;i<n-1;i++){
           read(x); read(y); read(w); //cin >> x >> y >> w;
            if(x>y) swap(x,y); //child always has higher id to parent
            tree[y][0] = x;tree[y][1] = w;//storing tree into array
            hash[x]++,hash[y]++; //storing frequency into hash
        }
        for(ll i = 2;i<=n;i++) //skip root node
            if(hash[i] == 1 ) Leaf[L++]=i,RealLeaf[i]=true;//freq == 1 means Leaf node..as simple as u think
        vector<vector<ll> > Jungle(n+5);
        vector<vector<ll> > graph(n+5,vector<ll>(n+5,0));// memset(graph,0,sizeof(graph));
        //for(int i =0;i<n+5;cout<<endl,i++) for(int j=0;j<n+5;cout<<graph[i][j]<<" ",j++)
        for(ll i=1;i<=n;i++) Jungle[i].push_back(i);
        vector<ll> ans(n+5,0); bool RootIncluded = false;
        while(1){
                //for(int i=0;i<Leaf.size();i++) cout<<Leaf[i]<<" "; cout<<endl;
                R=0;//Releaf.clear();
                for(int i=0,x,y;i<L;i++){
                    y=Leaf[i]; x=tree[y][0];
                    ll currmin=INT_MAX,prev=0; //cout<<"***"<<Leaf[i]<<" "<<(Jungle[y].size())<<endl;
                    //for(int j=0;j<Jungle[y].size();j++){  cout<<Jungle[y][j]<<" ";} cout<<endl;
                   //cout<<y<<" :: ";
                   for(int j=0;j<Jungle[y].size();j++){  prev=0; //cout<<Jungle[y][j]<<" ";
                        ll __n = NODE(Jungle[y][j],RealLeaf,graph,n,prev,Jungle[y][j]); //cout<<" : "<<__n<<endl;
                        currmin = min(currmin,__n);
                    }  //cout<<endl;
                    ans[y]=currmin;
                    if(RootIncluded==false){
                        for(int j=0;j<Jungle[y].size();j++)
                               Jungle[x].push_back(Jungle[y][j]);
                        //for next scenerio
                        graph[x][y] = graph[y][x] = tree[y][1];
                        hash[x]--; hash[y]--;
                        if(x!=1 && hash[x]==1) Releaf[R++]=x;
                    } else{}//last step,over don't do anything
                }
                if(R) {
                    for(ll i=0;i<R;i++){ Leaf[i]=Releaf[i];} L=R; R=0;
                }//Leaf=Releaf;
                else if(RootIncluded==false){ //cout<<"This time RooT -- >";
                    RootIncluded=true;  Leaf[0]=1;L=1;R=0;
                } else break;
        }
        for(int i=1;i<=n;i++) write(ans[i]);//cout<<ans[i]<<" ";cout<<endl;
    }
    return 0;
}
