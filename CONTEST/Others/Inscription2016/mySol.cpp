#include<bits/stdc++.h>
using namespace std;
int solve(int delH,int delM,int h1,int h2,int m1,int m2,int t1,int t2,int ans=0){
    h1%=12,h2%=12;
    while(true){
        if(m1==m2){
            if(h1==h2) break;
            if((h1==11 && (12+h1+delH)%12==0)||(h1==0 && (12+h1+delH)%12==11))  t1=1^t1;
            h1=(12+h1+delH)%12;     ans++;
        }else{
            if((m1==59 && (60+m1+delM)%60==0)||(m1==0 && (60+m1+delM)%60==59)){
                if((h1==11 && (12+h1+delM)%12==0)||(h1==0 && (12+h1+delM)%12==11)) t1=1^t1;
                     h1=(12+h1+delM)%12;
            }
            m1=(60+m1+delM)%60;     ans++;
        }
    }
    return !(t1==t2)+ans; //cout<<ans<<endl;
}

int main(){
	int t; cin >> t; while(t--){
		string s,k; cin >> s >> k;
		int h1 = (s[0]-'0')*10+(s[1]-'0'),m1 = (s[3]-'0')*10+(s[4]-'0'),t1=k[0]=='a';
		cin >>s >> k;
		int h2 = (s[0]-'0')*10+(s[1]-'0'),m2 = (s[3]-'0')*10+(s[4]-'0'),t2=k[0]=='a';
		int ans = min( solve(-1,-1,h1,h2,m1,m2,t1,t2),
                        min(solve(-1,1,h1,h2,m1,m2,t1,t2),
                            min(solve(1,-1,h1,h2,m1,m2,t1,t2),
                            solve(1,1,h1,h2,m1,m2,t1,t2)
                            )
                        )
                    );
		cout<<ans<<endl;
        }
    return 0;
}
