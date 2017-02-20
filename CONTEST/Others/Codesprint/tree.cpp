#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll r,cal; cin >> r;
    clock_t st = clock();
    double A,B,R;
    set<pair<ll,pair<ll,ll> > > s;
    for(ll a=1;a<=1000;a++){
        for(ll b=1;b<=1000;b++){
            for(ll c=1;c<=1000;c++){
                ll s2 = (a+b+c);
                ll D = (s2-a*2)*(s2-b*2)*(s2-c*2);
                ll N = 4*s2;

                if(D%N==0){
                    D=D/N;
                    if(r*r==D){
                        s.insert(make_pair(min(a,min(b,c)),make_pair(a+b+c-min(a,min(b,c))-max(a,max(b,c)),max(a,max(b,c)))));
                    }
                }
                A=(double)(b+c-a)*(c+a-b)*(a+b-c);
                B=(double)4*(a+b+c);
                R=(double)r*(double)r;
                if((A/B)>R) break;
            }
                A=(double)(b+1-a)*(1+a-b)*(a+b-1);
                B=(double)4*(a+b+1);

                R=(double)r*(double)r;
                if((A/B)>R) break;        }
        A=(double)(1+1-a)*(1+a-1)*(a+1-1);
        B=(double)4*(a+1+1);

                R=(double)r*(double)r;
                if((A/B)>R) break;
    }
    cout<<s.size()<<endl;
    for(set<pair<ll,pair<ll,ll> > >::iterator it=s.begin();it!=s.end();++it){
        cout<<(*it).first<<" "<<(*it).second.first<<" "<<(*it).second.second<<endl;
    }
    cout<<A<<" "<<B<<endl;
    clock_t ed = clock();
    double dur = (double)(ed-st)/CLOCKS_PER_SEC;
    cout<<dur<<endl;
}
