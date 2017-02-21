#include<bits/stdc++.h>
using namespace std;
int lps(string&seq, int i, int j)
{
   // Base Case 1: If there is only 1 character
   if (i == j)
     return 1;

   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;

   // If the first and last characters match
   if (seq[i] == seq[j])
      return lps (seq, i+1, j-1) + 2;

   // If the first and last characters do not match
   return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}
int main(){
    int q; cin >> q;
    while(q--){
        int n,k; cin >> n >> k;
        int ans=0;
        string str;cin >> str;
        int len = lps(str,0,n-1);
        for(char c='a';c<='z';c++){
            string curr=str;
            for(int i=0;i<n;i++){
                curr.insert(curr.begin()+i,c); //cout<<curr<<endl;
                int currLen = lps(curr,0,n);
                 if(currLen>=len+k)
                    ans++;
                curr.erase(curr.begin()+i);
            }
            curr.insert(curr.end(),c); //cout<<curr<<endl;
            int currLen = lps(curr,0,n);
            if(currLen>=len+k)
                ans++;
        }

        cout<<ans<<endl;
    }

}
