#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define x first
#define y second
#define Point pair<ld,ld>
ld dp[100005][2][2];
ld getDis(Point A,Point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
ld solve(int n, int x, int y,Point A,Point B,Point bin,vector<Point>&bot){
    if(n==0)
        return (x+y==0)?0:(1e12);
    if(dp[n][x][y]!=-1)
        return dp[n][x][y];
    ld ans = getDis(bin,bot[n])+getDis(bot[n],bin)+solve(n-1,x,y,A,B,bin,bot);
    if(x)
        ans = min(ans,getDis(A,bot[n])+getDis(bot[n],bin)+solve(n-1,x-1,y,A,B,bin,bot));
    if(y)
        ans = min(ans,getDis(B,bot[n])+getDis(bot[n],bin)+solve(n-1,x,y-1,A,B,bin,bot));
    return dp[n][x][y]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    Point A,B,bin; cin >> A.x >> A.y >> B.x >>  B.y >> bin.x >> bin.y ;;
    int n; cin >> n;
    vector<Point> bot(n+1); for(int i=1;i<=n;i++) cin >> bot[i].x >> bot[i].y;
    printf("%.9f\n",min(solve(n,1,1,A,B,bin,bot),min(solve(n,0,1,A,B,bin,bot),solve(n,1,0,A,B,bin,bot))));
    return 0;
}
