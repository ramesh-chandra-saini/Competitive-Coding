#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int A,B,temp;
    cin >> A >> B;
    long long int a[120],b[120];
    temp=A; for(int i=0;i<120;i++,temp/=2)  a[i]=(temp%2);
    temp=B; for(int i=0;i<120;i++,temp/=2) b[i]=(temp%2);
    for(int i=0;i<120/2;i++) swap(a[i],a[120-1-i]);
    for(int i=0;i<120/2;i++) swap(b[i],b[120-1-i]);

    long long int L=0,H=0,ans=0,c=0,d=0;

/*    for(int i=0;i<120;i++){
        c=c*2+a[i],d=d*2+b[i];
    }
    cout<<A<<" == "<<c<<" \t "<<d<<" == "<<B<<endl;*/
        c=0,d=0;
    for(int i=0;i<120;i++){
        c=c*2+a[i],d=d*2+b[i];
        if( (a[i]^b[i]) == 1 ){
            ans=ans*2+1;
            L=L*2+a[i],H=H*2+b[i];
        }else{
            if(a[i]== 0 && b[i]== 0 ){
                if(L*2+1<=H*2+b[i]){
                    ans=ans*2+1; L=L*2+1;H=H*2+0;
                }else{
                    ans=ans*2;L=L*2; H=H*2;
                }
            } else if(a[i] == 1 && b[i] == 1){
                if(L*2+a[i]<=H*2+0){
                    ans=ans*2+1;L=L*2+1;H=H*2+0;
                }else{
                    ans=ans*2+0;L=L*2+1;H=H*2+1;
                }
            }
        }
       // cout<<c<<"  "<<L<<"  "<<H<<"  "<<d<<" :: "<<ans<<endl;
    }
    //cout<<L<<" "<<H<<endl;
    cout<<ans<<endl;
    return 0;
}
