#include <bits/stdc++.h>
#define N 100010
#define pb push_back
using namespace std;
int main(){
 
    int t ; 
    cin >> t ;
 
    while( t-- ) {
        int n ;
        string str ;
 
        cin >> n >> str ;
        vector < int > zeroes ;
 
        int idx = 0 , ctr = 0 ;
 
        while( str[ idx ] == '0' ) idx++ ;
 
        for( int i = idx + 1 ; i < n ; i++ ) {
              if( str[ i ] == '0') ctr++ ;
              else {
                  if( ctr ) zeroes.pb( ctr ) ;
                  ctr = 0 ;
              }
        }
 
        for( int i = 0 ; i < idx ; i++ ) {
          if( str[ i ] == '0') ctr++ ;
          else {
              if( ctr ) zeroes.pb( ctr ) ;
              ctr = 0 ;
          }
        }
        if( ctr ) zeroes.pb( ctr ) ;
 
        if( zeroes.size() == 0 ) {
              cout << "0" << "\n" ;
              continue ;
        }
        int sum = 0;
        int mx = INT_MIN;
        for(int i=0;i<zeroes.size();i++)
            mx = max(mx,zeroes[i]),
            sum+=zeroes[i];
        cout<<sum-mx<<endl;
    }
 
    return 0;
} 
