#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int i,j,k,sum,ans,flag,len;
   char  a[100005],b[100005];
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        b[i]=a[len-i-1];

    }

   cout<<a<<b;



    return 0;
}
