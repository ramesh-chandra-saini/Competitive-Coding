#include <bits/stdc++.h>
using namespace std;
vector< vector <int  > > S;
void permute(vector<int > &a, int l, int r){
    if(l==r) {S.push_back(a); for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    }else{
        for(int i=l;i<=r;i++){
            swap(a[l],a[i]);
            permute(a,l+1,r);
            swap(a[i],a[l]);
        }
    } return;
}
int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    int n,x,y,c,m; cin >> n >>m;vector<int> arr(n); for(int i=0 ; i<n;i++)  arr[i]=i;
	    int graph[n ][ n]; memset( graph,0,sizeof(graph));
	    S.clear() ;permute(arr,0,n-1);
	    int M=1; for(int i=1;i <= n ;i++ ) M*=i;
	   while(m--){
	       cin >>x >>y >> c ; --x; --y;
	       graph[ x][ y] = graph[y ][ x] = graph[ x][ y]+c;
	       int diff[M];  vector<int> idx;for(int i=0; i<M; i++)idx.push_back(i);
            int xm=0,xl=0;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    int __M=INT_MIN,idif=abs(xm-xl);
                    for(int u=0;u<idx.size();u++){
                        int id=idx[u];int __m=0;
                        for(int j=i;j<n;j+=2)__m+=graph[S[id][i]][S[id][j]];
                        diff[id]=__m;
                        if(__M==INT_MIN) {__M=__m; }else{
                            if( abs(xm+_m-xl)>idif || abs(xm-_m-xl)>idif ){
                                __M=__m;
                            }
                        }
                    } if( abs(xm+__M-xl) > abs(xm-__M-xl)) xm+=__M; else xl+=__M;
                    vector<int> Rid; Rid.clear();
                    for(int u=0;u<idx.size();u++){
                        int id=idx[u];
                        if(diff[id]==__M) Rid.push_back(id);
                    } idx=Rid;
                }else{
                    int __M=INT_MAX,idif=abs(xm-xl);
                    for(int u=0;u<idx.size();u++){
                        int id=idx[u];int __m=0;
                        for(int j=i;j<n;j+=2)__m+=graph[S[id][i]][S[id][j]];
                        diff[id]=__m;
                         if(__M==INT_MAX) {__M=__m; }else{
                            if( abs(xm+_m-xl)>idif || abs(xm-_m-xl)>idif ){
                                __M=__m;
                            }
                        }

                    }
                    vector<int> Rid; Rid.clear();
                    for(int u=0;u<idx.size();u++){
                        int id=idx[u];
                        if(diff[id]==__M) Rid.push_back(id);
                    } idx=Rid;
                }
            }
            int id=idx[0];
            int ma=0,la=0;
            for(int i=0;i<n;i+=2){
                for(int j=i;j<n;j+=2) ma+=graph[S[id][i]][S[id][j]];
            }
            for(int i=1;i<n;i+=2){
                for(int j=i;j<n;j+=2) la+=graph[S[id][i]][S[id][j]];
            }
            cout<<(abs(ma-la))<<endl;
            cout<<abs(xl-xm)<<endl;
        }
	}
	return 0;
}
