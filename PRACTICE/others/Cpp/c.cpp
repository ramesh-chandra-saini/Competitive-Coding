#include<bits/stdc++.h>
using namespace std;

int main(){

    char s[100005];
    cin >> s;
    long long int ans=0,L=strlen(s),temp=0,d,prev,check;
    for(int i=0;i<min(L,18LL);i++)
        temp=temp*10+(s[i]-'0');
    if(L<=2)
        cout<<temp<<endl;
    else{
        ans=99;
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                d=j-i;
                prev=j;
                int flag=-1;

                if(i<(s[0]-'0')) flag=1;
                else if(i==(s[0]-'0')) flag=0;
                else break;

                if(flag==-1) break;
                else if(flag==0){
                    if(j<(s[1]-'0'))
                        flag=1;
                    else if(j==(s[1]-'0'))
                        flag=0;
                    else flag=-1;
                }

                if(flag==-1) break;

                for(int k=2;k<L && flag!=-1;k++){
                        check=(10+ (prev+d) )%10;
                        if(flag==1 ||(flag==0 && check<=s[k]-'0')){
                            ans++;
                            if(check<=s[k]-'0')
                            flag=1;
                        }
                        prev=check;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}
