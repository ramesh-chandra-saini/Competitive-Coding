#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;while(t--){
        int n; cin >> n;
        vector<vector<int> > arr(n,vector<int>(n,0));
        while(true){
            string type; cin >> type;
            if(type=="SET"){
                int x,y,num; cin >> x >> y >> num;
                arr[x][y]=num;
            }else if(type=="SUM"){
                int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
                int ans=0;
                for(int x=x1;x<=x2;x++){
                    for(int y=y1;y<=y2;y++){
                        ans+=arr[x][y];
                    }
                }
                cout<<ans<<endl;
            }else{
                break;
            } type.clear();
        }
        arr.clear();
    } return 0;
}
