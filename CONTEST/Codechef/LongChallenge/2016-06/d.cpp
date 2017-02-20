#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string ToString(int N){
    string ans; ans.clear();
    do{
        ans+=(N%10)+'0'; N/=10;
    }while(N);
    for(int i=0,j=ans.size()-1;i<j;i++,j--)
        swap(ans[i],ans[j]);
}
string Dharm(string s1,string s2){
    int zeros=0,ones=0;
    for(int i=0;i<s1.length();i++)
      {
          if(s1[i]!=s2[i])
          {
              if(s1[i]=='0')
              zeros++;
              else
              ones++;
          }
      }
      string ans; ans.clear();
      if(ones==0||zeros==0){
      printf("Unlucky Chef\n");
       ans="Unlucky Chef";
      }
      else
      {
       printf("Lucky Chef\n");
       printf("%lld\n",max(zeros,ones));
        ans="Lucky Chef";  ans+=ToString(max(zeros,ones));
      }
    return ans;
}
string Tester(string a, string b){
        string aCopy=b;
        int n=a.length();a.push_back('0'); a.push_back('1');
        //XOR Operation
        int ans=0,nextZero=1,nextOne=1;
        for(int i=0;i<n;i++){
            if(a[i]=='0' && b[i]=='1'){
                for(;;){
                    if(a[nextOne]=='1' && a[nextOne]!=b[nextOne]) break;
                    else nextOne++;
                }
                if(nextOne>=n) break;
                a[i]='1'; a[nextOne]='0'; ans++;
            }else if(a[i]=='1' && b[i]=='0'){
                for(;;){
                    if(a[nextZero]=='0' && a[nextZero]!=b[nextZero]) break;
                    else nextZero++;
                }
                if(nextZero>=n) break;
                a[i]='0'; a[nextZero]='1'; ans++;
            }
        } //cout<<"XOR : ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        //OR operation
        int static_one=-1;
        for(int i=0;i<n;i++)
            if(a[i]=='1' && b[i]=='1') {static_one=i; break;}
        if(static_one!=-1)
            for(int i=0;i<n;i++)
                if(a[i]=='0' && b[i]=='1') a[i]='1', ans++;
        //cout<<"OR : ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        //AND operation
        int static_zero=-1;
        for(int i=0;i<n;i++)
            if(a[i]=='0' && b[i]=='0') {static_zero=i; break;}
        if(static_zero!=-1)
            for(int i=0;i<n;i++)
                if(a[i]=='1' && b[i]=='0') a[i]='0', ans++;
        //cout<<"AND : ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        //cout<<ans<<" ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        a.erase(a.begin()+n,a.end());
        string ANS;ANS.clear();
        if(a==b) {cout<<"Lucky Chef"<<endl<<ans<<endl; ANS="Lucky Chef";ANS+=ToString(ans);}
        else {cout<<"Unlucky Chef"<<endl; ANS="Unlucky Chef";}
        return ANS;
    }
int main()
{
  ll t;

  scanf("%lld",&t);
  string A,B;
  while(t--)
  {
      ll ones=0,zeros=0;
      string s1,s2;
      int N=rand()%100;
      for(int i=0;i<N;i++){
        s1+=rand()%2+'0';
        s2+=rand()%2+'0';
      }
     // cin>>s1>>s2;
    if(Dharm(s1,s2)!=Tester(s1,s2)) { A=s1;B=s2; }
  }
  cout<<A<<" "<<B<<endl;
}
