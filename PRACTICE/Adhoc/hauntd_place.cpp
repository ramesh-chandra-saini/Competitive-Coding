#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int t,n,i,j,m,top,left,bottom,right;
    cin>>t;

    while(t--)
    {
       long long int flag=0;
        cin >> n>> m;

        char arr[n][m];

        top=INT_MAX;
        bottom=INT_MIN;
        left=INT_MAX;
        right=INT_MIN;


        for(i=0;i<n;i++)
         cin>>arr[i];

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){

               if(arr[i][j]=='*')
               {
                   flag=1;
                   top=min(top,i);
                   bottom=max(bottom,i);
                   left=min(left,j);
                   right=max(right,j);
               }
            }
        }

           long long int ans=INT_MAX;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
            {
              if(arr[i][j]=='*')
              {

                 long long int mx=max((i-top),(bottom-i));
                 long long int mn=max((j-left),(right-j));
                 long long int res=max(mx,mn);
                  ans=min(ans,res);
              }
            }
        }

            if(ans!=INT_MAX)   printf("%d\n",++ans);
            else   printf("0\n");
    }

 return(0);
}
