// C program for implementation of KMP pattern searching
// algorithm
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int lps[100000000];
void computeLPSArray(string &pat, int M)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
    lps[0] = 0; // lps[0] is always 0
    i = 1;
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example
           // AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
    for(int i=0;i<M;i++) cout<<lps[i]<<" "; cout<<endl;
    return;
}

// Driver program to test above function
int main(){

   int n,m; cin >> n;m=n;
   string A,B; cin >> A >> B; B+=B;
   computeLPSArray(A, A.length());

    int res = 0, best = 0, ans = 0;
    int j = 0;
    int i   = 0;
    n*=2;
    while(i < n) {
        if(A[j] == B[i]) {
            j++;
            i++;
            best++;
        }
        if(best > res) {
            res = best;
            ans = i-j;
        }
        if(j == m) {
            break;
        }
        if(A[j] != B[i]) {
            best = 0;
            if(j != 0) {
                j = lps[j-1];
            }else {
                i++;
            }
        }
    }
    printf("%d\n",ans);

   return 0;
}
