#include<bits/stdc++.h>
using namespace std;
string text,pattern;
int eraser[200005];
bool mark_erased[200005];
bool check(int pos,int N){
    for(int i=0;i<N;i++) //flush old value from mark_erased
        mark_erased[i]=false;
    for(int i=0;i<pos;i++) //marking erased element till pos
        mark_erased[eraser[i]]=true;
    for(int i=0,j=0;i<N;i++){
        if(!mark_erased[i]){ //this element is not erased
                             //we need to find matching for this...
            if(pattern[j]==text[i]){
                j++; //move to next character for matching..
                if(j>=pattern.length()) //completely matched
                    return true;
            }else ; //if it not matched

                    //we will check with next unerased character
        }
    }
    return false;
}
int main(){
    cin>>text;
    cin >>pattern;
    int N=text.length();
    for(int i=0;i<N;i++)
      cin>>eraser[i],--eraser[i];
    int low=0,high=N-1,ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,N))
            ans = mid,low=mid+1;
        else
            high = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
