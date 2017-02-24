#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long int
#define INT_MAX  100
#define INT_MIN -1
vector<ll> T_sum(1000006,0);
ll build_sum(ll L, ll R, vector<ll> &arr,ll id){
    if(L>R) //invalid segment
        return 0;
    if(L==R) // at leaf node
        return T_sum[id] = arr[L];
    ll mid = (L+R)/2;
    return T_sum[id] = build_sum(L,mid,arr,2*id)+build_sum(mid+1,R,arr,2*id+1);
}
ll update_sum(ll ss, ll se, ll idx , ll value,ll id){
    if(ss == se){
        T_sum[id]=value;
    }else{
        ll mid = (ss + se) / 2;
        if(ss <= idx and idx <= mid)
            update_sum(ss, mid, idx, value,2*id);
        else
            update_sum(mid+1, se, idx, value,2*id+1);
        T_sum[id] = T_sum[2*id] + T_sum[2*id+1];
    }
    return T_sum[id];
}
ll query_sum(ll ss,ll se,ll qs,ll qe,ll id){
    if(ss>se || qs>qe || se<qs || qe<ss)
        return 0;
    if(qs<=ss && se<=qe)
        return T_sum[id];
    ll mid = (ss+se)/2;
    return query_sum(ss,mid,qs,qe,2*id)+query_sum(mid+1,se,qs,qe,2*id+1);
}
vector<pair<ll,ll> > T_max(1000006,pair<ll,ll> (INT_MIN,INT_MIN));
pair<ll,ll> pair_set_max(pair<ll,ll> left,pair<ll,ll> right){
    set<ll> st;
    st.clear();
    set<ll> ::iterator it;
    ll k = 0;
    pair<ll,ll> ans = mp(INT_MIN,INT_MIN);
    if(left.first!=INT_MIN)
        st.insert(-left.first);
    if(left.second!=INT_MIN)
        st.insert(-left.second);
    if(right.first!=INT_MIN)
        st.insert(-right.first);
    if(right.second!=INT_MIN)
        st.insert(-right.second);
    for(k=0,it=st.begin();k<2 && it!=st.end();++it,++k)
        (k==0)?ans.first = -*it:ans.second=-*it;
    return ans;
}
pair<ll,ll> build_max(ll L, ll R, vector<ll> &arr,ll id){
    if(L>R) //invalid segment
        return mp(INT_MIN,INT_MIN);
    if(L==R) // at leaf node
        return T_max[id] = mp(arr[L],INT_MIN);
    ll mid = (L+R)/2;
    return T_max[id] = pair_set_max(build_max(L,mid,arr,2*id),build_max(mid+1,R,arr,2*id+1));
}
pair<ll,ll> update_max(ll ss,ll se, ll idx,ll value,ll id){

    if(ss == se){
        T_max[id]=mp(value,INT_MIN);
    }else{
        ll mid = (ss + se) / 2;
        if(ss <= idx and idx <= mid)
            update_max(ss, mid, idx, value,2*id);
        else
            update_max(mid+1, se, idx, value,2*id+1);
        T_max[id] = pair_set_max(T_max[2*id] , T_max[2*id+1]);
    }
    return T_max[id];
}
pair<ll,ll> query_max(ll ss,ll se,ll qs,ll qe,ll id){
    if(ss>se || qs>qe || se<qs || qe<ss)
        return mp(INT_MIN,INT_MIN);
    if(qs<=ss && se<=qe)
        return T_max[id];
    ll mid = (ss+se)/2;
    return pair_set_max(query_max(ss,mid,qs,qe,2*id),query_max(mid+1,se,qs,qe,2*id+1));
}
vector<pair<ll,ll> > T_min(1000006,pair<ll,ll>(INT_MAX,INT_MAX));
pair<ll,ll> pair_set_min(pair<ll,ll> left,pair<ll,ll> right){
    set<ll> st;
    st.clear();
    set<ll> ::iterator it;
    ll k = 0;
    pair<ll,ll> ans = mp(INT_MAX,INT_MAX);
    if(left.first!=INT_MAX)
        st.insert(left.first);
    if(left.second!=INT_MAX)
        st.insert(left.second);
    if(right.first!=INT_MAX)
        st.insert(right.first);
    if(right.second!=INT_MAX)
        st.insert(right.second);
    for(k=0,it=st.begin();k<2 && it!=st.end();++it,++k)
        (k==0)?ans.first = *it:ans.second=*it;
    return ans;
}
pair<ll,ll> build_min(ll L, ll R, vector<ll> &arr,ll id){
    if(L>R) //invalid segment
        return mp(INT_MAX,INT_MAX);
    if(L==R) // at leaf node
        return T_min[id] = mp(arr[L],INT_MAX);
    ll mid = (L+R)/2;
    return T_min[id] = pair_set_min(build_min(L,mid,arr,2*id),build_min(mid+1,R,arr,2*id+1));
}
pair<ll,ll> update_min(ll ss,ll se,ll idx,ll value,ll id){

    if(ss == se){
        T_min[id]=mp(value,INT_MAX);
    }else{
        ll mid = (ss + se) / 2;
        if(ss <= idx and idx <= mid)
            update_min(ss, mid, idx, value,2*id);
        else
            update_min(mid+1, se, idx, value,2*id+1);
        T_min[id] = pair_set_min(T_min[2*id] , T_min[2*id+1]);
    }
    return T_min[id];
}
pair<ll,ll> query_min(ll ss,ll se,ll qs,ll qe,ll id){
    if(ss>se || qs>qe || se<qs || qe<ss)
        return mp(INT_MAX,INT_MAX);
    if(qs<=ss && se<=qe)
        return T_min[id];
    ll mid = (ss+se)/2;
    return pair_set_min(query_min(ss,mid,qs,qe,2*id),query_min(mid+1,se,qs,qe,2*id+1));
}
void print(vector<ll> &T,ll N){
    for(ll i=1;i<=3*N;i++)
        cout<<T[i]<<" "; cout<<endl;
}
void print(vector<pair<ll,ll> > &T,ll N){
    for(ll i=1;i<=3*N;i++)
        cout<<T[i].first<<" "<<T[i].second<<"  "; cout<<endl;
}
int main(){
//    freopen("in.txt","r",stdin);
    ll N; cin >> N;
    vector<ll> arr(N+1);
    for(ll i=1;i<=N;i++)
        cin >> arr[i];
    build_sum(1,N,arr,1);

    build_max(1,N,arr,1);
    build_min(1,N,arr,1);
    ll Q; cin >> Q;
    while(Q--){
        char q; cin >> q;
        ll L,R,I,V; cin >> L >> R;
        pair<ll,ll> p;
        //cout<<"ans"<<"  ==> ";
        switch(q){
            case 'A':  //find sum
                    cout<<query_sum(1,N,L,R,1);
            break;
            case 'M': // maximum number
                    p=query_max(1,N,L,R,1);
                    cout<<p.first;
            break;
            case 'm': //minimum number
                    p=query_min(1,N,L,R,1);
                    cout<<p.first;
            break;
            case 'S': //second maximum number
                    p = query_max(1,N,L,R,1);
                    //cout<<p.first<<" "<<p.second<<endl;
                    (p.second==INT_MIN)?cout<<"NA":cout<<p.second;

            break;
            case 's': //second maximum number
                    p = query_min(1,N,L,R,1);
                    (p.second==INT_MAX)?cout<<"NA":cout<<p.second;
            break;
            case 'U': //update values
                if(L>=1 && L<=N)
                    I=L,V=R,arr[I]=V,//cout<<"update "<<I<<" "<<V<<endl,
                    update_sum(1,N,I,V,1),
                    update_max(1,N,I,V,1),
                    update_min(1,N,I,V,1);
                else
                    cout<<"NA";
            break;
            default: //invalid operations
                cout<<"!!!";
            break;
        }
        if(q!='U')
        cout<<"\n";
        //for(ll i=1;i<=N;i++)
         //   cout<<arr[i]<<" ";cout<<endl;
        //print(T_min,N),print(T_max,N);
        //print(T_sum,N);
    }
}
