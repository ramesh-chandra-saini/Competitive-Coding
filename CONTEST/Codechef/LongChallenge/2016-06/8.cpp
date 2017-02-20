#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define point pair<long double,long double >
#define x first
#define y second
point center;
bool __cmp (const point a, const point b)
{
    if (a.x - center.x >= 0 && b.x - center.x < 0)
        return !true;
    if (a.x - center.x < 0 && b.x - center.x >= 0)
        return !false;
    if (a.x - center.x == 0 && b.x - center.x == 0) {
        if (a.y - center.y >= 0 || b.y - center.y >= 0)
            return !(a.y > b.y);
        return !(b.y > a.y);
    }

    // compute the cross product of vectors (center -> a) x (center -> b)
    long double det = (a.x - center.x) * (b.y - center.y) - (b.x - center.x) * (a.y - center.y);
    if (det < 0)
        return !true;
    if (det > 0)
        return !false;

    // points a and b are on the same line from the center
    // check which point is closer to the center
    double d1 = (a.x - center.x) * (a.x - center.x) + (a.y - center.y) * (a.y - center.y);
    double d2 = (b.x - center.x) * (b.x - center.x) + (b.y - center.y) * (b.y - center.y);
    return !(d1 > d2);
}

void SORTING(long double X[],long double Y[],ll N){
    vector<point> DS;DS.clear();
    for(int i=0;i<N;i++){
        DS.push_back(make_pair(X[i],Y[i]));
        center.first+=X[i];
        center.second+=Y[i];
    }
    center.x = center.x/(long double)N;
    center.y = center.y/(long double)N;
    for(int i=0;i<DS.size();i++){
        DS[i].first+=center.x;
        DS[i].second+=center.y;
    }

    sort(DS.begin(),DS.end(),__cmp);
    for(int i=0;i<DS.size();i++){
        X[i]=DS[i].first+center.x;
        Y[i]=DS[i].second+center.y;
    }
    DS.clear();
}
long double X[100005],Y[100005];
multiset<point > eset;
int main(){

    ll T,Q,x,y,freq,N; cin >> T;
    char c;
    while(T--){
        cin >> Q ; N=0; eset.clear();
        while(Q--){
        cin >> c >> x >> y;
        point Pair=make_pair(x,y);
        if(c=='+') eset.insert(Pair);
        else eset.erase(Pair);
        long double area1=0,area2=0,i=0;
        N=0;
        set<point > pset;pset.clear();
        for(multiset<point > :: iterator it=eset.begin();it!=eset.end();++it)
            pset.insert(make_pair(it->first,it->second));
        for(set<point> :: iterator it=pset.begin();it!=pset.end();++it)
            X[N]=it->first,Y[N]=it->second,N++;

     //   for(int i=0;i<N;i++) cout<<"("<<X[i]<<","<<Y[i]<<") "; cout<<endl;
        SORTING(X,Y,N);
        for(int i=0,j=1;i<N;i++,j++){
            area1+=(X[i]*Y[(j%N)]);
            area2+=(Y[i]*X[(j%N)]);
        }
        long double area = abs(area1-area2)/(long double)2.0;
        cout<<area<<endl;
        }
    }

    return 0;
}
