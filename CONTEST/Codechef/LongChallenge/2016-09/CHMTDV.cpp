#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX (1LL<<62)

map<pair<ll,ll>,ll> valueHolder;
set< pair<ll,pair<ll,ll> > > heap;
set<ll> h,v;
vector<vector<ll> >arr(500+1,vector<ll>(500+1,0LL)),dp(500+1,vector<ll>(500+1,0LL));
void print(){
    for(set<ll>::iterator it=h.begin();it!=h.end();++it)
        printf("%lld ",*it);printf("\n");
    for(set<ll>::iterator it=v.begin();it!=v.end();++it)
        printf("%lld ",*it); printf("\n");

    for(set<pair<ll,pair<ll,ll> > >::iterator it=heap.begin();it!=heap.end();++it){
        cout<<-it->first<<"["<<it->second.first<<","<<it->second.second<<"] ";
    } cout<<endl;
    for(map<pair<ll,ll>,ll >::iterator it=valueHolder.begin();it!=valueHolder.end();++it){
        cout<<-it->second<<"["<<it->first.first<<","<<it->first.second<<"] ";
    } cout<<endl;
}
ll getGridSum(ll prevI,ll prevJ,ll I, ll J){
    ll ans=dp[I][J]-dp[I][prevJ]-dp[prevI][J]+dp[prevI][prevJ];
    //cout<<"["<<prevI<<","<<prevJ<<"] ["<<I<<" "<<J<<"] "<<ans<<"="<<dp[I][J]<<"-"<<dp[I][prevJ]<<"-"<<dp[prevI][J]<<"+"<<dp[prevI][prevJ]<<endl;
    return ans;
}
ll getPrevious(set<ll>&A,ll a){
    ll ans=0;    //cout<<"GetPrevious";
    set<ll>::iterator it=A.find(a);
    if(it!=A.end() && it!=A.begin()){
        --it; ans=*it;
    }//cout<<"["<<a<<"] "<<ans<<endl;
    return ans;
}
ll getNext(set<ll>&A,ll a){
    ll ans=0; //cout<<"GetNext";
    set<ll>::iterator it=A.find(a);
    if(it!=A.end()){
        ++it;
        if(it!=A.end()){
            ans=*it;
        }
    }//cout<<"["<<a<<"] "<<ans<<endl;
    return ans;
}
void randomization(ll p,ll n){
    srand(time(NULL));
    while(h.size()<p-1){
        ll k=1+rand()%(n-1);
        h.insert(k);
    }
    while(v.size()<p-1){
        ll k=1+rand()%(n-1);
        v.insert(k);
    }
    //for(set<ll>::iterator it=h.begin();it!=h.end();++it)cout<<*it<<" ";cout<<endl;
    //for(set<ll>::iterator it=v.begin();it!=v.end();++it) cout<<*it<<" ";cout<<endl;
}
void surity(ll p,ll n){
    for(ll ct=1;ct<p;ct++)
        h.insert(ct),v.insert(ct);
    //for(set<ll>::iterator it=h.begin();it!=h.end();++it)cout<<*it<<" ";cout<<endl;
    //for(set<ll>::iterator it=v.begin();it!=v.end();++it) cout<<*it<<" ";cout<<endl;
}

void preprocessing(ll n){
    ///horizontal Cummulation
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1]+arr[i][j];
        }
    }
    ///verticle Cummulation
    for(ll j=1;j<=n;j++){
        for(ll i=1;i<=n;i++){
            dp[i][j]+=dp[i-1][j];
        }
    }
    /*for( ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        } cout<<endl;
    }
    print();*/
}
void prepareGrid(){
    //for(set<ll>::iterator it=h.begin();it!=h.end();++it) cout<<*it<<" ";cout<<endl;
    //for(set<ll>::iterator it=v.begin();it!=v.end();++it) cout<<*it<<" ";cout<<endl;
    set<ll>::iterator i=h.begin();
    for(++i;i!=h.end();i++){
        set<ll>::iterator j=v.begin();
        for(++j;j!=v.end();j++){
            ll prevI=getPrevious(h,*i);
            ll prevJ=getPrevious(v,*j);
            ll I=*i;
            ll J=*j;
           // cout<<"{ ["<<prevI<<" "<<prevJ<<"] <--> ["<<I<<","<<J<<"]  }"<<endl;
            ll value = getGridSum(prevI,prevJ,I,J);
            heap.insert(make_pair(-value,make_pair(I,J)));
            valueHolder.insert(make_pair(make_pair(I,J),-value));
        }
    }
//    print();
}
void selectGrid(ll &I,ll &J,ll &value){
        set<pair<ll,pair<ll,ll> > >::iterator it=heap.begin();
        value = -it->first;
        I=it->second.first;
        J=it->second.second;
        //cout<<"["<<I<<","<<J<<"] "<<value<<endl;
}
ll shrinkFromRight(ll I,ll J,ll value,ll N){
    if(J==N||J-getPrevious(v,J)<=1){
        return MAX;
    }else{
        ll nextMax=0;
        ll nextJ=getNext(v,J);
        set<ll>::iterator it = h.begin();
        for(++it;it!=h.end();++it){
            nextMax=max(nextMax,getGridSum(getPrevious(h,*it),J-1,*it,nextJ));
        }
        return nextMax;
    }
}
void updateRightShrink(ll I,ll J,ll value,ll N){
    //handle right shift
    //cout<<"right Shrink["<<I<<","<<J<<"]"<<endl;
    set<ll>::iterator it = h.begin();
    ll nextJ=getNext(v,J);
    for(++it;it!=h.end();++it){
        ll val = valueHolder[make_pair(*it,nextJ)];
        valueHolder.erase(make_pair(*it,nextJ));
        heap.erase(make_pair(val,make_pair(*it,nextJ)));
    }
    it = h.begin();
    for(++it;it!=h.end();++it){
        ll val = valueHolder[make_pair(*it,J)];
        valueHolder.erase(make_pair(*it,J));
        heap.erase(make_pair(val,make_pair(*it,J)));
    }
    it = h.begin();
    for(++it;it!=h.end();++it){
        ll val = getGridSum(getPrevious(h,*it),J-1,*it,nextJ);
        valueHolder[make_pair(*it,nextJ)]=-val;
        heap.insert(make_pair(-val,make_pair(*it,nextJ)));
    }
    it = h.begin();
    ll prevJ=getPrevious(v,J);
    for(++it;it!=h.end();++it){
        ll val = getGridSum(getPrevious(h,*it),prevJ,*it,J-1);
        valueHolder[make_pair(*it,J-1)]=-val;
        heap.insert(make_pair(-val,make_pair(*it,J-1)));
    }
    v.erase(J);
    v.insert(J-1);
}
ll shrinkFromLeft(ll I,ll J,ll value,ll N){
    ll prevJ=getPrevious(v,J);
    if(prevJ==0||J-prevJ<=1){
        return MAX;
    }else{
        ll nextMax=0;
        set<ll>::iterator it = h.begin();
        ll prevJ=getPrevious(v,J);
        ll prevPrevJ=getPrevious(v,prevJ);
        for(++it;it!=h.end();++it){
            nextMax=max(nextMax,getGridSum(getPrevious(h,*it),prevPrevJ,*it,prevJ+1));
        }
        return nextMax;
    }
}
void updateLeftShrink(ll I,ll J,ll value,ll N){
    //handle left shift
        //cout<<"left Shrink["<<I<<","<<J<<"]"<<endl;
    set<ll>::iterator it = h.begin();
    ll prevJ=getPrevious(v,J);
    for(++it;it!=h.end();++it){
        ll val = valueHolder[make_pair(*it,prevJ)];
        valueHolder.erase(make_pair(*it,prevJ));
        heap.erase(make_pair(val,make_pair(*it,prevJ)));
    }
    it = h.begin();
    for(++it;it!=h.end();++it){
        ll val = valueHolder[make_pair(*it,J)];
        valueHolder.erase(make_pair(*it,J));
        heap.erase(make_pair(val,make_pair(*it,J)));
    }
    it = h.begin();
    ll prevPrevJ=getPrevious(v,prevJ);
    for(++it;it!=h.end();++it){
        ll val = getGridSum(getPrevious(h,*it),prevPrevJ,*it,prevJ+1);
        valueHolder[make_pair(*it,prevJ+1)]=-val;
        heap.insert(make_pair(-val,make_pair(*it,prevJ+1)));
    }
    it = h.begin();
    for(++it;it!=h.end();++it){
        ll val = getGridSum(getPrevious(h,*it),prevJ+1,*it,J);
        valueHolder[make_pair(*it,J)]=-val;
        heap.insert(make_pair(-val,make_pair(*it,J)));
    }
    v.erase(prevJ);
    v.insert(prevJ+1);
}
ll shrinkFromDown(ll I,ll J,ll value,ll N){
    if(I==N||I-getPrevious(h,I)<=1){
        return MAX;
    }else{
        ll nextMax=0;
        set<ll>::iterator it = v.begin();
        ll nextI=getNext(h,I);
        for(++it;it!=v.end();++it){
            nextMax=max(nextMax,getGridSum(I-1,getPrevious(v,*it),nextI,*it));
        }
        return nextMax;
    }
}
void updateDownShrink(ll I,ll J,ll value,ll N){
    //handle down shift
        //cout<<"down Shrink["<<I<<","<<J<<"]"<<endl;
    set<ll>::iterator it = v.begin();
    ll nextI=getNext(h,I);
    for(++it;it!=v.end();++it){
        ll val = valueHolder[make_pair(nextI,*it)];
        valueHolder.erase(make_pair(nextI,*it));
        heap.erase(make_pair(val,make_pair(nextI,*it)));
    }
    it = v.begin();
    for(++it;it!=v.end();++it){
        ll val = valueHolder[make_pair(I,*it)];
        valueHolder.erase(make_pair(I,*it));
        heap.erase(make_pair(val,make_pair(I,*it)));
    }
    it = v.begin();
    for(++it;it!=v.end();++it){
        ll val = getGridSum(I-1,getPrevious(v,*it),nextI,*it);
        valueHolder[make_pair(nextI,*it)]=-val;
        heap.insert(make_pair(-val,make_pair(nextI,*it)));
    }
    it = v.begin();
    ll prevI=getPrevious(h,I);
    for(++it;it!=v.end();++it){
        ll val = getGridSum(prevI,getPrevious(v,*it),I-1,*it);
        valueHolder[make_pair(I-1,*it)]=-val;
        heap.insert(make_pair(-val,make_pair(I-1,*it)));
    }
    h.erase(I);
    h.insert(I-1);
}
ll shrinkFromUp(ll I,ll J,ll value,ll N){
    ll prevI=getPrevious(h,I);
    if(prevI==0||I-prevI<=1){
        return MAX;
    }else{
        ll nextMax=0;
        set<ll>::iterator it = v.begin();
        ll prevPrevI=getPrevious(h,prevI);
        for(++it;it!=v.end();++it){
            nextMax=max(nextMax,getGridSum(prevPrevI,getPrevious(v,*it),prevI+1,*it));
        }
        return nextMax;
    }
}
void updateUpShrink(ll I,ll J,ll value,ll N){
    //handle up shift
        //cout<<"up Shrink["<<I<<","<<J<<"]"<<endl;
    set<ll>::iterator it = v.begin();
    ll prevI=getPrevious(h,I);
    for(++it;it!=v.end();++it){
        ll val = valueHolder[make_pair(prevI,*it)];
        valueHolder.erase(make_pair(prevI,*it));
        heap.erase(make_pair(val,make_pair(prevI,*it)));
    }
    it = v.begin();
    for(++it;it!=v.end();++it){
        ll val = valueHolder[make_pair(I,*it)];
        valueHolder.erase(make_pair(I,*it));
        heap.erase(make_pair(val,make_pair(I,*it)));
    }
    it = v.begin();
    ll prevPrevI=getPrevious(h,prevI);
    for(++it;it!=v.end();++it){
        ll val = getGridSum(prevPrevI,getPrevious(v,*it),prevI+1,*it);
        valueHolder[make_pair(prevI+1,*it)]=-val;
        heap.insert(make_pair(-val,make_pair(prevI+1,*it)));
    }
    it = v.begin();
    for(++it;it!=v.end();++it){
        ll val = getGridSum(prevI+1,getPrevious(v,*it),I,*it);
        valueHolder[make_pair(I,*it)]=-val;
        heap.insert(make_pair(-val,make_pair(I,*it)));
    }
}
void handleShrink(ll I,ll J,ll value,ll N){
    //cout<<"Handle Shrink : ["<<I<<" "<<J<<"]@"<<value<<endl;
    ll currValue=value;
    ll targetedValue = MAX;// cout<<MAX<<endl;
    ll RightShrinkValue=shrinkFromRight(I,J,value,N);targetedValue=min(targetedValue,RightShrinkValue);
    ll LeftShrinkValue=shrinkFromLeft(I,J,value,N);targetedValue=min(targetedValue,LeftShrinkValue);
    ll DownShrinkValue=shrinkFromDown(I,J,value,N);targetedValue=min(targetedValue,DownShrinkValue);
    ll UpShrinkValue=shrinkFromUp(I,J,value,N);targetedValue=min(targetedValue,UpShrinkValue);
    //cout<<"currValue "<<currValue<<" "<<"targetedValue "<<targetedValue<<endl;
    if(targetedValue>=currValue || targetedValue==MAX){
        //cout<<"NO Shrinking "<<endl;
        return;
    }else{
        if(RightShrinkValue==targetedValue){
            updateRightShrink(I,J,value,N);
        }else if(LeftShrinkValue==targetedValue){
            updateLeftShrink(I,J,value,N);
        }else if(DownShrinkValue==targetedValue){
            updateDownShrink(I,J,value,N);
        }else if(UpShrinkValue==targetedValue){
            updateUpShrink(I,J,value,N);
        }
    }
}
int main(){

    ll n,p; scanf("%lld%lld",&n,&p);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            scanf("%lld",&arr[i][j]);
        }
    }
    h.clear(),v.clear(),valueHolder.clear(),heap.clear();
    //randomization(p,n);
    surity(p,n);
    preprocessing(n);
    h.insert(n),v.insert(n); //insert downmost and righmost boundry
    h.insert(0),v.insert(0);//insert upmost and leftmost boundary
    prepareGrid();

    ll TLE=CLOCKS_PER_SEC/(1000LL),process=0;
    //ll TLE=5,process=0;
    //print();
    while(TLE--){
        ll I,J,value;
        //cout<<"Select"<<endl;
        selectGrid(I,J,value);
        //cout<<"Shrink"<<endl;
        handleShrink(I,J,value,n);
       // print();
    }
    h.erase(n), v.erase(n); //remove downmost and righmost boundry
    h.erase(0),v.erase(0);//remove upmost and leftmost boundary

    for(set<ll>::iterator it=h.begin();it!=h.end();++it)
        printf("%lld ",*it);printf("\n");
for(set<ll>::iterator it=v.begin();it!=v.end();++it)
        printf("%lld ",*it); printf("\n");

    return 0;
}
