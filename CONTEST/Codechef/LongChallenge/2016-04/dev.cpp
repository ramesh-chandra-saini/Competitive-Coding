#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool LoopFlag=true;
ll ANS=0;
void prArr(int arr[],int e){
    for(int i=0;i<e;i++) cout<<arr[i]; cout<<endl;
}
int Hamming(string &A,string &B,int L){
   int H=0;
    for(int i=0;i<L;i++)
        if(A[i]!=B[i]) ++H;
    return H;
}
void nextStr(string &s,int L,int A){
    char c = 'a'+A; s[0]++; int j=0;
    for(int i=0;i<L;i++){
        if(s[i]<c) return ;
        else {s[i]='a';++s[i+1];j=i+1;}
    }

     return;
}
bool AP(string &s,int L){
    for(int i=0;i<L;i++){
        for(int j=i+1;j<L;j++){
           int k = 2*j-i;
            if(k<L && i!=j && i!=k && j!=k && s[i]==s[j] && s[i]==s[k] && s[j]==s[k]) return false;
        }
    } return true;
}

bool __AP(int s[],int L,int A){
    bool flag=false;//no such pattern
     for(int i=0;i<L;i++){ bool Changer=false;int id=0;
        for(int j=i+1;j<L;j++){
           int k = 2*j-i;++id;
           while(id<=k && id<L && Changer) { s[id++]=0;} if(id==L) Changer=false;
            if(k<L && i!=j && i!=k && j!=k && s[i]==s[j] && s[i]==s[k] && s[j]==s[k]) {id=k; Changer=true;

                for(int u=id;u>=0;u--){
                    s[u]++;
                    if(s[u]==A) s[u]=0;
                    else break;
                }
                id=k;
            flag=true;}//pattern found
        }
    }
    return flag;
}
int __HM(int Sarr[],int __n[],int L){
    int H=0LL;
    for(int i=0;i<L;i++)
        if(Sarr[i]!=__n[i]) ++H;
    return H;
}
void __nextSTr(int __n[],int L,int A){
    int carr=1;
    for(int i=L-1;i>=0;i--){
        __n[i]+=carr;
        if(__n[i]==A){__n[i]=0; carr=1;}
        else {carr=0;return;}
    }
    if(carr)LoopFlag=false;
}
int ___HM(string & str, string & s, int L){
    int H=0;
    for(int i=0;i<L;i++)
        if(str[i]!=s[i]) ++H;
    return H;
}
bool ___AP(string &s,int L){
    bool flag=false;//no such pattern
     for(int i=0;i<L;i++){
        for(int j=i+1;j<L;j++){
           int k = 2*j-i;
            if(k<L && i!=j && i!=k && j!=k && s[i]==s[j] && s[i]==s[k] && s[j]==s[k]) {flag=true; return true;}//pattern found
        }
    }
    return flag;
}
bool APVaibhav(char s[],int L){

    for(int i=0;i<=L;i++){
        for(int j=i+1;j<=L;j++){
           int k = 2*j-i;
            if(k<=L && i!=j && i!=k && j!=k && s[i]==s[j] && s[i]==s[k] && s[j]==s[k]) return true;
        }
    } return false;
}
 //recVaibhav(str,idx,s,K,A,HD,Length);
void recVaibhav(char str[], int idx, string &s, int K,int A,int HD,int Length){

    for(int i=0;i<A;i++){
        str[idx]='a'+i;
        bool Found = APVaibhav(str,idx);
        if(Found == false){//ap condition is  not present
            bool HDInc=false;if(str[idx]!=s[idx]) HDInc=true;//calculate hd
            if(HD+HDInc<=K){ if(idx+1==Length)ANS++;
                if(idx+1<Length){
                    recVaibhav(str,(idx+1),s,K,A,(HD+HDInc),Length);
                }
            }
        }
    }
    return;
}
int main(){
//std::cout << std::numeric_limits<long long>::max();
   int T,A,K,L,idx,ans=0; scanf("%d",&T); long long int N;
    while(T--){
        scanf("%d%d",&A,&K);string s,t; ll ct=0;
        cin >> s; L=s.length();
        if(L>8 && A == 2){printf("0\n");}
        else if(L<=12 || A == 1){
                N=pow(A,L);ans=0LL;//printf("%intd %intd  ",L,N);
                for(int i=0;i<L;i++) t+='a'; //print(t,L);
                for(int i=0;i<N;i++){ //print(t,L);
                    bool flag=AP(t,L);
                    if(Hamming(s,t,L)<=K &&  flag ) ans++;
                    nextStr(t,L,A);
                }
            printf("%d\n",ans); //s.clear();t.clear();
        } else{
            if(L>26) printf("0\n");
            else{
                char str[L]; ///for(int p=0;p<L;p++) str[p]='a';
                ANS=0; int idx=0; int HD=0;
                recVaibhav(str,idx,s,K,A,HD,L);
                printf("%d\n",ANS);

            /*
            LoopFlag = true;//global looper
                ans=0LL;
                int Sarr[L]; for(int i=0;i<L;i++)  Sarr[i]=s[i]-'a'; //prArr(Sarr,1,L);
                int __n[L];for(int i=0;i<L;i++) __n[i]=0; ct=0LL;
                for(;LoopFlag ;){ ct++; //cout<<ct<<"\t";
                    bool flag =__AP(__n,L,A);
                    if(flag == true){//skip
                        /*int i=idx+1;
                        for(;i<L;i++) {__n[i]=(A-1); }//skipping remaining string aaaxxxx ... => aaaccc...c => aabaaaa..a

                    }else {
                        if( __HM(Sarr,__n,L)<=K ) {ans++; prArr(__n,L);} //else  prArr(__n,L);
                        __nextSTr(__n,L,A);
                    }
                }
               printf("%lld\n",ans); //cout<<ct<<endl;
               */
            }
        }
    }
    return 0;
}

