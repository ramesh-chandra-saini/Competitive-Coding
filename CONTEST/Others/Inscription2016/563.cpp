#include<bits/stdc++.h>
using namespace std;
int solve(int H1,int h2,int m1,int m2,int t1,int T2){
int ans = INT_MAX,a,t2=T2,h1=H1,prev;

                //++
				a= (m2-m1+60)%60;
			if(m2>m1){
                a+=(h2-h1+12)%12;t2=T2,h1=H1;
				if(h2>=h1)
                    a+=(t2==t1)?0:1;
				else
                    a+=(t2!=t1)?0:1;
			}else if(m2<m1){
			       prev=h1;
				t2=T2,h1=H1;h1++;
				t2 =(h1>=12&&prev<12)?1^t2:t2;
                a+=(h2-h1+12)%12;
                if(h2>=h1)
					a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			}else{
                t2=T2,h1=H1;
                a+=(h2-h1+12)%12;
                if(h2>=h1)
					t2 =(h2>=12||h2<=0)?1^t2:t2,a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;

			}
			ans = min(ans,a);a=0;cout<<ans<<endl;
			 //-+
			 a= (m1-m2+60)%60;
			if(m2>m1){
			   prev=h1;

                t2=T2,h1=H1;h1--;
                   				t2 =(h1<=0&&prev>0)?1^t2:t2;
				a+=(h2-h1+12)%12;
				if(h2>=h1)
					a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			}else if(m2<m1){
				t2=T2,h1=H1;
                a+=(h2-h1+12)%12;
				if(h2>=h1)
					a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			}else{
                t2=T2,h1=H1;
				a+=(h2-h1+12)%12;
				if(h2>=h1)
					a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
            } ans = min(ans,a);a=0;cout<<ans<<endl;
            //+- MH
            a= (m2-m1+60)%60;
            if(m2>m1){
				a+=(h1-h2+12)%12;
				t2=T2,h1=H1;
                if(h2>=h1)
					a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			}else if(m2>m1){
			     prev=h1;
				t2=T2,h1=H1;h1++;
				t2 =(h1>=12&&prev<12)?1^t2:t2;
				a+=(h1-h2+12)%12;
				if(h2>=h1)
					a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			} else{
                t2=T2,h1=H1;
				a+=(h1-h2+12)%12;
				if(h2>=h1)
				    a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			}
			ans = min(ans,a);a=0; cout<<ans<<endl;
            //--
            a= (m1-m2+60)%60;
			if(m2>m1){
			  prev=h1;
                t2=T2,h1=H1;h1--;
                t2 =(h1<=0&&prev>0)?1^t2:t2;
				a+=(h1-h2+12)%12;
                if(h2>=h1)
                   a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			}else if(m2<m1){
				t2=T2,h1=H1;
                a+=(h1-h2+12)%12;
				if(h2>=h1)
				   a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			}else{
			t2=T2,h1=H1;
				a+=(h1-h2+12)%12;
                if(h2>=h1)
				     a+=(t2==t1)?0:1;
				else
					a+=(t2!=t1)?0:1;
			} ans = min(ans,a);a=0;
        return ans;
}
int main(){
	int t; cin >> t; while(t--){
		string s,k; cin >> s >> k;
		int H1 = (s[0]-'0')*10+(s[1]-'0'),m1 = (s[3]-'0')*10+(s[4]-'0'),t1=k[0]=='a';
		cin >>s >> k;
		int h2 = (s[0]-'0')*10+(s[1]-'0'),m2 = (s[3]-'0')*10+(s[4]-'0'),T2=k[0]=='a';
		//cout<<H1<<" "<<m1<<" "<<t1<<" "<<h2<<" "<<m2<<" "<<T2<<endl;
        cout<<min(solve(H1,h2,m1,m2,t1,T2),solve(h2,H1,m2,m1,T2,t1))<<endl;
        }
    return 0;
}
