/*
    Author : Ramesh Chandra
    Suggested By : Vaibhav Salve
    National Institute Of Technology Karnataka Surathkal
*/
#include<bits/stdc++.h>
using namespace std;
int ANS=0;//store Answer
void prStr(char arr[],int e){ for(int i=0;i<e;i++) cout<<arr[i]; printf("\",");cout<<endl;}
bool APVaibhav(char t[],int L){ //don't check for every pair..only check with newly entered character..n/2
    for(int i=L%2;i<L;i+=2){//take only odd and odd or even even
        int j=(L+i)/2; if(t[i]==t[j] && t[i]==t[L]) return true;
    } return false;
}
void recVaibhav(char t[], int idx, char s[], int K,int A,int HD,int Length){ //purposed by Vaibhav but designed by me..
    for(int i=0;i<A;i++){
        t[idx]='a'+i;
        bool Found = APVaibhav(t,idx);//check for AP is found..through this string.... take a new string
        if(Found == false){//ap condition is  not present
            bool HDInc=false;if(t[idx]!=s[idx]) HDInc=true;//calculate hd
            if(HD+HDInc<=K){ if(idx+1==Length){ANS++; //printf("\""); prStr(t,Length);
                                }
                if(idx+1<Length){//valid case to go forward
                    recVaibhav(t,(idx+1),s,K,A,(HD+HDInc),Length);
                }
            }
        }
    }
    return; //now you are done...take a rest..solve next problem
}
int main(){
   int T,A,K,L,idx,ans=0; scanf("%d",&T);
   char STR[49][27]={"aabbaabcbccacaababbcaccbcb",
"aabbcaacacbbccbbcacaacbbaa",
"aabcbaacacbbccbbcacaabcbaa",
"aacbcaababccbbccbabaacbcaa",
"aaccaacbcbbabaacaccbabbcbc",
"aaccbaababccbbccbabaabccaa",
"abaababccbbccbabaabccaacac",
"ababbaacbbcbcaaccaacbcbbca",
"ababbaacbbcbcaaccaacbcbbcb",
"ababbcbaacaccbcbbabaccaacc",
"abccbcbaabbaabcbccbaaccaca",
"acaacacbbccbbcacaacbbaabab",
"acaccaabccbcbaabbaabcbccba",
"acaccaabccbcbaabbaabcbccbc",
"acaccbcaababbcbccacabbaabb",
"acbbcbcaaccaacbcbbcaabbaba",
"babaabbcaacacbbccbbcacaaca",
"babaabbcaacacbbccbbcacaacb",
"babaacabbcbccacaababccbbcc",
"babbabaccaaccababbaccbbcbc",
"baccacabbaabbacaccabbccbcb",
"bbaabbacaccbcbbabaacbccaca",
"bbaacbbcbcaaccaacbcbbcaabb",
"bbacabbcbcaaccaacbcbbacabb",
"bbcacbbabaccaaccababbcacbb",
"bbccabbabaccaaccababbaccbb",
"bbccbbcacaababbcbccabaacac",
"bcaacacbbccbbcacaacbbaabab",
"bcbbcbcaaccaacbcbbcaabbaba",
"bcbccacbbabaacaccbcbaabbaa",
"bcbccbbaccacabbaabbacaccab",
"bcbccbbaccacabbaabbacaccac",
"cabbabaccaaccababbaccbbcbc",
"cacaabaccbcbbabaacacbbccbb",
"cacaaccbaababccbbccbabaaba",
"cacaaccbaababccbbccbabaabc",
"caccacabbaabbacaccabbccbcb",
"cbaababccbbccbabaabccaacac",
"cbcbbabccacaababbcbcaaccaa",
"cbcbbccabbabaccaaccababbab",
"cbcbbccabbabaccaaccababbac",
"cbccbcbaabbaabcbccbaaccaca",
"ccaabccbcbaabbaabcbccbaacc",
"ccaaccababbcbccacaabcbbaba",
"ccabaccbcbaabbaabcbccabacc",
"ccbabccacabbaabbacaccbabcc",
"ccbbaccacabbaabbacaccabbcc",
"ccbbccbabaacaccbcbbacaabab"};
    while(T--){
        scanf("%d%d",&A,&K);char s[50],t[50];
        scanf("%s",s); L=strlen(s);
        if(A==1){  if(L<=2) printf("1\n");else printf("0\n");}//simple observation for A=1
        else if(A==2 && L>=9)printf("0\n");//some interesting fact about A=2 hint given by Vaibhav
        else if(A==3 && L>26) printf("0\n");//again tried for A =3 same as A=2..got some pattern
        else if(A==3 && L==26){ //after submitting same solution..only give TLE for last subtask..simple Hack..:D
            ANS=0;
            for(int i=0;i<48;i++){ int h=0;
                for(int j=0;j<26;j++)
                    if(STR[i][j]!=s[j]) h++;
                if(h<=K) ANS++;
            } printf("%d\n",ANS);
        } else{//solving problem in bruteforce manner as problem setter has mentioned....but doing great work to optimize algorithm
                ANS=0; int idx=0; int HD=0;
                recVaibhav(t,idx,s,K,A,HD,L);
                printf("%d\n",ANS);
        }
    }
    return 0;
}
