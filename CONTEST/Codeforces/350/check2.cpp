#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  char str[100001];
  cin>>str;
  int L=strlen(str);
  int A[L],i,j,k;
  for(i=0;i<L;i++){

    A[i]=str[i]-'0'; }
   //for(i=0;i<L;i++) cout<<A[i]; cout<<endl;
   /*check it if is divisible by 8 of its single digit*/

   bool flag=false;
   int ind=0;
   for(i=0;i<L;i++)
   {
     if(A[i]%8==0){
        ind=i;
        flag=true;
        break;
     }
   }
   if(flag){

       cout<<"YES"<<endl;
       cout<<A[ind]<<endl;
   }
   else
   {
       flag=false;
       int a=0,b=0,c=0;
       int num;
       for(i=0;i<L;i++)
       {
          for(j=i+1;j<L;j++)
          {
             num=A[i]*10+A[j];

             if(num%8==0)
             {
                a=i;b=j;
                flag=true;
                break;
             }
          }
       }
       if(flag) {

          cout<<"YES"<<endl;
          num=A[a]*10+A[b];
          cout<<num<<endl;
       }
       else
       {
          flag=false;
             a=0;b=0;c=0;
          for(i=0;i<L;i++)
          {

             for(j=i+1;j<L;j++)
             {

               for(k=j+1;k<L;k++)
               {
                  num=A[i]*100+A[j]*10+A[k];
                  if(num%8==0){

                    a=i; b=j; c=k;
                    flag=true;
                    break;

                  }
               }
             }
          }

          if(flag)
          {
              cout<<"YES"<<endl;
              num=A[a]*100+A[b]*10+A[c];
              cout<<num<<endl;
          }
          else cout<<"NO"<<endl;

       }
   }


  return 0;
}
