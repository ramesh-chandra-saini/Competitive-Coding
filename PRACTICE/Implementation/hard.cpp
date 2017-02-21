#include<bits/stdc++.h>
using namespace std;
pair< pair<double,double>,int> center(make_pair(make_pair(0,0),0));
bool bit=false;
double getSlop(const pair<pair<double,double>,int> &X, const pair<pair<double,double>,int>&Y){
    if(X.first.first==Y.first.first) return DBL_MAX;
    return ((Y.first.second-X.first.second)/(Y.first.first-Y.first.second));
}
bool __cmp(const pair<pair<double,double>,int>&a, const pair<pair<double,double>,int>&b){
    double A = getSlop(a,center);
    double B = getSlop(b,center);
    if(A!=B) {
        if(bit==true){
            return A<=B;
        }else{
            return A>=B;
        }
    } //return A<=B;//first sort by angle
    A=pow(a.first.first,2)+pow(a.first.second,2);
    B= pow(b.first.first,2)+pow(b.first.second,2);
    return A<=B;//sort by distance

}
double getDis(pair<double,double>&A,pair<double,double>&B){
    return (A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second);
}
int main(){
    int n,a,b; cin >> n >> a >> b;a-=1,b-=1;
    vector< pair< pair<double,double>, int > > arr(n);

    double x,y;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        arr[i].first.first  = x,
        arr[i].first.second = y;
        arr[i].second       = i;
        center.first.first+=x,center.first.second+=y;
    }
    vector<pair<pair<double,double>,int> >temp(arr);
    center.first.first/=(double)n,center.first.second/=(double)n;
   // cout<<center.first.first<<" "<<center.first.second<<endl;
    for(int i=0;i<arr.size();i++)
        arr[i].first.first-=center.first.first,arr[i].first.second-=center.first.second;
    vector<int> visit(arr.size(),false);
    vector<pair<pair<double,double>,int> > PP; PP.clear();
    for(int i=0;i<arr.size();i++){
        if(arr[i].first.first>=0 && arr[i].first.second>=0 && visit[i]==false){
            visit[i]=true,PP.push_back(arr[i]);
        }
    }
    vector<pair<pair<double,double>,int> > MP; MP.clear();
    for(int i=0;i<arr.size();i++){
        if(arr[i].first.first<0 && arr[i].first.second>=0 && visit[i]==false){
            visit[i]=true,MP.push_back(arr[i]);
        }
    }
    vector<pair<pair<double,double>,int> > MM; MM.clear();
    for(int i=0;i<arr.size();i++){
        if(arr[i].first.first<0 && arr[i].first.second<0 && visit[i]==false){
            visit[i]=true,MM.push_back(arr[i]);
        }
    }
    vector<pair<pair<double,double>,int> > PM; PM.clear();
    for(int i=0;i<arr.size();i++){
        if(arr[i].first.first>=0 && arr[i].first.second<0 && visit[i]==false){
            visit[i]=true,PM.push_back(arr[i]);
        }
    }
    bit=true,sort(PP.begin(),PP.end(),__cmp);
    bit=false,sort(MP.begin(),MP.end(),__cmp);
    bit=true,sort(MM.begin(),MM.end(),__cmp);
    bit=false,sort(PM.begin(),PM.end(),__cmp);


    arr.clear();
    for(int i=0;i<PP.size();i++)
        arr.push_back(temp[PP[i].second]);
    for(int i=0;i<MP.size();i++)
        arr.push_back(temp[MP[i].second]);
    for(int i=0;i<MM.size();i++)
        arr.push_back(temp[MM[i].second]);
    for(int i=0;i<PM.size();i++)
        arr.push_back(temp[PM[i].second]);

    //for(int i=0;i<n;i++) arr[i].first.first+=center.first.first,arr[i].first.second+=center.first.second;
   for(int i=0;i<n;i++) cout<<"["<<arr[i].first.first<<","<<arr[i].first.second<<"] ";cout<<endl;

    double ans=0;
    int idx =0;
    for(int i=0;i<n;i++){
        if(arr[i].second==a){
            idx=i;
            break;
        }
    }
    int prev=idx;
    double right=0;
    for(int j=(idx+1)%n;;j=(j+1)%n){
        right+=getDis(arr[j].first,arr[prev].first);
        if(j==b)
            break;
        prev=j;
    }
    prev=idx;
    double left =0;
    for(int j=(n+(idx-1))%n;;j=(n+(j-1))%n){
        left+=getDis(arr[j].first,arr[prev].first);
        if(j==b)
            break;
        prev=j;
    }
    cout<<left<<" "<<right<<endl;
    ans=max(left,right);
    cout<<ans<<endl;
    ans=sqrt(ans);
    cout<<ans<<endl;
    return 0;
}
