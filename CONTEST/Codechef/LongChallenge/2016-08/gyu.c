#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#include<string.h>
int main()
{
   char name[30] = "Hello";

   printf("String before strrev( ) : %s\n",name);

   printf("String after strrev( )  : %s",strrev(name));

   return 0;
}
