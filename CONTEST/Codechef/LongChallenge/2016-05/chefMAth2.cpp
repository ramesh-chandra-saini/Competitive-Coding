/*
AUTHOR : RAMESH CHANDRA
FINAL YEAR CSE STUDENT NITK SURATHKAL
NOTE:JUST RECURSIVE SOLUTION AND NO OPTIMIZATION :)P
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000000
#define pb push_back
#define mp make_pair
vector<ll> ___fib;
vector<ll> Present;
void Fibo(){
    ll a=1,b=2,c;
    ___fib.pb(a);___fib.pb(b);
    while(a+b<=MAX)
        c=a+b,___fib.pb(c),a=b,b=c;
    //for(ll i=0;i<___fib.size();i++)cout<<___fib[i]<<"  "; cout<<"\t("<<___fib.size()<<")"<<endl;
}
bool bin(vector<ll> &___fib,ll s,ll e,ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(___fib[m]==key) return true;
    else if(___fib[m]<key) return bin(___fib,m+1,e,key);
    else return bin(___fib,s,m-1,key);
}
void findNextNearest(vector<ll> &___fib,ll s, ll e,ll key,ll &ans){
    if(s>e) return;
    ll m=(s+e)/2LL;
    if(___fib[m]>key){
        ans=min(ans,___fib[m]);
        return findNextNearest(___fib,s,m-1,key,ans);
    }else return findNextNearest(___fib,m+1,e,key,ans);
}
bool binSearch(vector<ll> & Present,ll s,ll e, ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(Present[m]==key) return true;
    if(Present[m]<key) return binSearch(Present,m+1LL,e,key);
    return binSearch(Present,s,m-1LL,key);
}
void Checker(){

    clock_t startTime=clock();
    Fibo();
    ll a=1LL,b=2LL,c;
    vector<pair<ll,ll> > list; list.clear();
    Present.clear();Present.pb(a); Present.pb(b);
    list.pb(mp(a,1));list.pb(mp(b,1));
    //cout<<"Base Terms :\n1)."<<a<<"("<<"1"<<")   \n2). "<<b<<"("<<"1"<<")"<<endl;
    ll i=0,j=1;
    ll Terminator=1000000005,terms=3,newTerm=2,freq=1;
    for(;i<j && Terminator--;){/*
AUTHOR : RAMESH CHANDRA
FINAL YEAR CSE STUDENT NITK SURATHKAL
NOTE:JUST RECURSIVE SOLUTION AND NO OPTIMIZATION :)P
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000000
#define pb push_back
#define mp make_pair
vector<ll> ___fib;
vector<ll> Present;
void Fibo(){
    ll a=1,b=2,c;
    ___fib.pb(a);___fib.pb(b);
    while(a+b<=MAX)
        c=a+b,___fib.pb(c),a=b,b=c;
    //for(ll i=0;i<___fib.size();i++)cout<<___fib[i]<<"  "; cout<<"\t("<<___fib.size()<<")"<<endl;
}
bool bin(vector<ll> &___fib,ll s,ll e,ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(___fib[m]==key) return true;
    else if(___fib[m]<key) return bin(___fib,m+1,e,key);
    else return bin(___fib,s,m-1,key);
}
void findNextNearest(vector<ll> &___fib,ll s, ll e,ll key,ll &ans){
    if(s>e) return;
    ll m=(s+e)/2LL;
    if(___fib[m]>key){
        ans=min(ans,___fib[m]);
        return findNextNearest(___fib,s,m-1,key,ans);
    }else return findNextNearest(___fib,m+1,e,key,ans);
}
bool binSearch(vector<ll> & Present,ll s,ll e, ll key){
    if(s>e) return false;
    ll m=(s+e)/2LL;
    if(Present[m]==key) return true;
    if(Present[m]<key) return binSearch(Present,m+1LL,e,key);
    return binSearch(Present,s,m-1LL,key);
}
void Checker(){

    clock_t startTime=clock();
    Fibo();
    ll a=1LL,b=2LL,c;
    vector<pair<ll,ll> > list; list.clear();
    Present.clear();Present.pb(a); Present.pb(b);
    list.pb(mp(a,1));list.pb(mp(b,1));
    //cout<<"Base Terms :\n1)."<<a<<"("<<"1"<<")   \n2). "<<b<<"("<<"1"<<")"<<endl;
    ll i=0,j=1;
    ll Terminator=1000000005,terms=3,newTerm=2,freq=1;
    for(;i<j && Terminator--;){
        newTerm=list[i].first+list[j].first;
        freq=list[i].second+list[j].second;
        bool flag=true;
        if(bin(___fib,0,___fib.size()-1,newTerm)==true){
            list.pb(mp(newTerm,1));
            //cout<<terms++<<"). "<<list[i].first<<"("<<list[i].second<<")  + "<<list[j].first<<"("<<list[j].second<<")"<<" = "<<newTerm<<"("<<"1"<<")";
            i=0;
            j=list.size()-1;
            //printf("  ___fib[%lld] : %lld , ___fib[%lld] : %lld \n",i,list[i].first,j,list[j].first);
            //cout<<newTerm<<" ";
            Present.pb(newTerm); flag=false;
        }else if(freq<=10){ flag=false;
            list.pb(mp(newTerm,freq));
            //cout<<terms++<<"). "<<list[i].first<<"("<<list[i].second<<")  + "<<list[j].first<<"("<<list[j].second<<")"<<" = "<<newTerm<<"("<<freq<<")"<<endl;
            i++;
            //cout<<newTerm<<" ";
            Present.pb(newTerm);
        }
        if(i==j || flag){
            ll Next=INT_MAX;
            findNextNearest(___fib,0,___fib.size()-1,newTerm,Next);
            if(Next==INT_MAX) break;
            else{
                newTerm=Next;list.pb(mp(newTerm,1));
                //cout<<terms++<<"). "<<list[i].first<<"("<<list[i].second<<")  + "<<list[j].first<<"("<<list[j].second<<")"<<" = ";
      //          cout<<"# "<<newTerm<<"("<<"1"<<")"<<endl;
                i=0;j=list.size()-1;
              //  cout<<newTerm<<" ";
                Present.pb(newTerm);
            }
        }
    }
    //cout<<"\nLast Accessed Term : "<<newTerm<<" \nListSize : "<<list.size()<<endl;
    //cout<<double(list.size()/newTerm)<<endl;
    //clock_t endTime=clock();
    //double duration = (float)(endTime-startTime)/CLOCKS_PER_SEC;
    //cout<<duration<<endl;
    //cout<<Present.size()<<endl;
 //   return binSearch(Present,0,Present.size()-1,item);
}
ll solve(vector<ll> &__fib, ll N,ll K,ll X){
   if(K==0 && X==0)  return 1LL;//exact answer
   if(K>0&& N>=0&& X>0) return solve(__fib,N,K-1,X-__fib[N])+solve(__fib,N-1,K,X);//break into subproblems
   return 0LL;//invalid cases
}
int main() {
	ll t; scanf("%lld",&t);
    Checker();//to prepare list of number which can be represented as sum of firbonacci number using atmost 10 fibonacci numbers
	while(t--){
	    ll K,X; scanf("%lld%lld",&X,&K);
	    if(binSearch(Present,0LL,Present.size()-1LL,X)==false) printf("0\n");//check existence
	    else{
            ll temp=X,id=___fib.size()-1,count=0LL;
            while(temp>0LL &&id>=0LL){
               if(temp>=___fib[id]) temp-=___fib[id],count++;
               else id--;
             }
             if(count>K) printf("0\n");
             else printf("%lld\n",solve(___fib,___fib.size()-1,K,X));//recursive solution
        }
	}
	return 0;
}
        newTerm=list[i].first+list[j].first;
        freq=list[i].second+list[j].second;
        if(bin(___fib,0,___fib.size()-1,newTerm)==true){
            list.pb(mp(newTerm,1));
            //cout<<terms++<<"). "<<list[i].first<<"("<<list[i].second<<")  + "<<list[j].first<<"("<<list[j].second<<")"<<" = "<<newTerm<<"("<<"1"<<")";
            i=0;
            j=list.size()-1;
            //printf("  ___fib[%lld] : %lld , ___fib[%lld] : %lld \n",i,list[i].first,j,list[j].first);
            //cout<<newTerm<<" ";
            Present.pb(newTerm);
        }else if(freq<=10){
            list.pb(mp(newTerm,freq));
            //cout<<terms++<<"). "<<list[i].first<<"("<<list[i].second<<")  + "<<list[j].first<<"("<<list[j].second<<")"<<" = "<<newTerm<<"("<<freq<<")"<<endl;
            i++;
            //cout<<newTerm<<" ";
            Present.pb(newTerm);
        }
        if(i==j){
            ll Next=INT_MAX;
            findNextNearest(___fib,0,___fib.size()-1,newTerm,Next);
            if(Next==INT_MAX) break;
            else{
                newTerm=Next;list.pb(mp(newTerm,1));
                //cout<<terms++<<"). "<<list[i].first<<"("<<list[i].second<<")  + "<<list[j].first<<"("<<list[j].second<<")"<<" = ";
      //          cout<<"# "<<newTerm<<"("<<"1"<<")"<<endl;
                i=0;j=list.size()-1;
              //  cout<<newTerm<<" ";
                Present.pb(newTerm);
            }
        }
    }
    //cout<<"\nLast Accessed Term : "<<newTerm<<" \nListSize : "<<list.size()<<endl;
    //cout<<double(list.size()/newTerm)<<endl;
    //clock_t endTime=clock();
    //double duration = (float)(endTime-startTime)/CLOCKS_PER_SEC;
    //cout<<duration<<endl;
    //cout<<Present.size()<<endl;
 //   return binSearch(Present,0,Present.size()-1,item);
}
ll solve(vector<ll> &__fib, ll N,ll K,ll X){
   if(K==0 && X==0)  return 1LL;//exact answer
   if(K>0&& N>=0&& X>0) return solve(__fib,N,K-1,X-__fib[N])+solve(__fib,N-1,K,X);//break into subproblems
   return 0LL;//invalid cases
}
int main() {
	ll t; scanf("%lld",&t);
    Checker();//to prepare list of number which can be represented as sum of firbonacci number using atmost 10 fibonacci numbers
	while(t--){
	    ll K,X; scanf("%lld%lld",&X,&K);
	    if(binSearch(Present,0LL,Present.size()-1LL,X)==false) printf("0\n");//check existence
	    else{
            ll temp=X,id=___fib.size()-1,count=0LL;
            while(temp>0LL &&id>=0LL){
               if(temp>=___fib[id]) temp-=___fib[id],count++;
               else id--;
             }
             if(count>K) printf("0\n");
             else printf("%lld\n",solve(___fib,___fib.size()-1,K,X));//recursive solution
        }
	}
	return 0;
}
