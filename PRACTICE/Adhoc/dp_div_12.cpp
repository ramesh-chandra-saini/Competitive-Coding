
   #include<bits/stdc++.h>
   using namespace std;

   #define MAXLEN 1005
   #define   MAXN 1005

    int len,ar[MAXLEN],dp[MAXLEN][MAXN],n;
    int fun(int idx,int m)
    {
        if(idx==len)                        // One sub-sequence completed
            return (m==0);                    // return 1 only if modulus by n is 0
        if(dp[idx][m]!=-1)
            return dp[idx][m];
        int ans=fun(idx+1,m);                // skip this element in current sub-sequence
        ans+=fun(idx+1,(m*10+ar[idx])%n);    // Include this element. Find the new modulo by 'n' and pass it recursively
        return dp[idx][m]=ans;
    }
    int main()
    {

        int len;
        cin >> len;

        int arr[len];

        for(int i=0;i<len;i++)
            cin >> arr[i];
        n=6;

        // input len , n , array
        for(int i=0;i<MAXLEN;i++){
            for(int j=0;j<MAXLEN;j++){
                dp[i][j]=-1;
            }
        }
        printf("%d\n",fun(0,0));            // initially we begin by considering array of length 1 i.e. upto index 0
        return 0;
    }
