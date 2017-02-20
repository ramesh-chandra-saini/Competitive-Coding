/*
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int T;
    scanf("%d",&T);
    char A[100001],B[100001];

    while(T--){

        scanf("%s%s",A,B);

        int N=0,J=0,S=0,common=0;
        int a[26],b[26],A_length=strlen(A),B_length=strlen(B);
        for(int i=0;i<26;i++)
            a[i]=b[i]=0;
        //Hashing: Store frequencies of both strings
        for(int i=0;i<A_length;++i)
            a[A[i]-'a']++;
        for(int i=0;i<B_length;++i)
            b[B[i]-'a']++;
        //same character and same position
        for(int i=0;i<A_length && i<B_length;i++)
            if(A[i]==B[i])
                N++,a[A[i]-'a']--,b[B[i]-'a']--;
        //same character and different position
        for(int i=0;i<26;i++){
            common=min(a[i],b[i]);
            J+=common,a[i]-=common,b[i]-=common;
        }
        //different character in string A
        for(int i=0;i<26;i++)
            S+=a[i];
        printf("%dN%dJ%dS\n",N,J,S);
    }
    return 0;
}
