#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> fib;
void Fibo(){
	ll a=1LL,b=2LL,c;
	fib.clear(); fib.push_back(a); fib.push_back(b);
	while(a+b<=1000000000LL)
        c=a+b,fib.push_back(c),a=b,b=c;
}
bool bin(ll s,ll e,ll key){
    if(s>e)return false;
    ll m=(s+e)/2LL;
    if(fib[m]==key) return true;
    if(fib[m]<key) return bin(m+1LL,e,key);
    return bin(s,m-1LL,key);
}
ll solve(ll Num,ll K){

    if(K==1){
        return bin(0LL,fib.size()-1,Num);
    }
    if(Num==1){
        return K==1LL;
    } ll f1,f2;
    for(ll i=fib.size()-1;i>=0;i--){
        if(Num>fib[i]){
            f1=fib[i], f2=Num-fib[i];break;
        }
    } //cout<<Num<<" := "<<f1<<" + "<<f2<<endl;
    for(ll i=1LL;i<K;i++){
        return solve(f1,i) + solve(f2,K-i);
    }
}
int main(){

	int t; cin >> t;
	Fibo();
	while(t--){
		int X,K; cin >> X >> K ; ll temp=X;
		vector<ll> fibParts; fibParts.clear();
		 for(ll i=fib.size()-1;i>=0;i--){
                if(temp>=fib[i]){
                    fibParts.push_back(fib[i]);
                    temp-=fib[i];
                }
        }//cout<<X<<" := "<<fibParts[0]; for(ll i=1;i<fibParts.size();i++) cout<<" + "<<fibParts[i]; cout<<endl;
        ll ans=0LL;
        if(K<fibParts.size()) ans=0LL;
        else if(K==fibParts.size()) ans=1LL;
        else if(K==1){
            ans=bin(0LL,fib.size()-1,X);
        }
        else{
            for(ll _1=1LL;_1<K && K>=1LL;_1++){
                if(fibParts.size()==1LL && _1==K) {ans=solve(fibParts[0],_1); break; }
                for(ll _2=1LL;_2<K && K>=2LL;_2++){
                    if(fibParts.size()==2LL && _1+_2==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2); break; }
                    for(ll _3=1LL;_3<K && K>=3LL;_3++){
                        if(fibParts.size()==3LL && _1+_2+_3==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3); break; }
                        for(ll _4=1LL;_4<K && K>=4LL;_4++){
                            if(fibParts.size()==4LL && _1+_2+_3+_4==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3)+solve(fibParts[3],_4); break; }
                            for(ll _5=1LL;_5<K && K>=5LL;_5++){
                                if(fibParts.size()==5LL && _1+_2+_3+_4+_5==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3)+solve(fibParts[3],_4)+solve(fibParts[4],_5); break; }
                                for(ll _6=1LL;_6<K && K>=6LL;_6++){
                                    if(fibParts.size()==6LL && _1+_2+_3+_4+_5+_6==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3)+solve(fibParts[3],_4)+solve(fibParts[4],_5)+solve(fibParts[5],_6); break; }
                                    for(ll _7=1LL;_7<K && K>=7LL;_7++){
                                        if(fibParts.size()==7LL && _1+_2+_3+_4+_5+_6+_7==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3)+solve(fibParts[3],_4)+solve(fibParts[4],_5)+solve(fibParts[5],_6)+solve(fibParts[6],_7); break; }
                                        for(ll _8=1LL;_8<K && K>=8LL;_8++){
                                            if(fibParts.size()==8LL && _1+_2+_3+_4+_5+_6+_7+_8==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3)+solve(fibParts[3],_4)+solve(fibParts[4],_5)+solve(fibParts[5],_6)+solve(fibParts[6],_7)+solve(fibParts[7],_8); break; }
                                            for(ll _9=1LL;_9<K && K>=9LL;_9++){
                                                if(fibParts.size()==9LL && _1+_2+_3+_4+_5+_6+_7+_8+_9==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3)+solve(fibParts[3],_4)+solve(fibParts[4],_5)+solve(fibParts[5],_6)+solve(fibParts[6],_7)+solve(fibParts[7],_8)+solve(fibParts[8],_9); break; }
                                                for(ll _10=1LL;_10<K && K>=10LL;_10++){
                                                    if(fibParts.size()==10LL && _1+_2+_3+_4+_5+_6+_7+_8+_9+_10==K) {ans=solve(fibParts[0],_1)+solve(fibParts[1],_2)+solve(fibParts[2],_3)+solve(fibParts[3],_4)+solve(fibParts[4],_5)+solve(fibParts[5],_6)+solve(fibParts[6],_7)+solve(fibParts[7],_8)+solve(fibParts[8],_9)+solve(fibParts[9],_10); break; }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
