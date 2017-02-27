#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]; cout<<endl;
}
void maximizePalindrome(int i,int j,vector<int>&arr,vector<bool>&changedDigit,int K){
    if(i>j)  return; //processed fully
    if(K<0)  return ; //no mare changes allowed
    if(arr[i]==9 && arr[j]==9) //both had their max
        maximizePalindrome(i+1,j-1,arr,changedDigit,K);
    if(i==j){ //midle element
        if(changedDigit[i]==true || K>=1) //either you had changed previously or one more changed still allowed
            arr[i]=arr[j]=9;//that was middle element,We're Done!!
    }else{
        int req_K = !changedDigit[i] + !changedDigit[j];
        if(K>=req_K)
            arr[i]=arr[j]=9,//changed both digit
            maximizePalindrome(i+1,j-1,arr,changedDigit,K-req_K);
    }
}
int ConvertIntoPalindrome(int i,int j, vector<int>&arr,vector<bool>&changedDigit){
    if(i>j) //you're done!!!
        return 0;
    if(arr[i]==arr[j])//no need to flip these digits
        return ConvertIntoPalindrome(i+1,j-1,arr,changedDigit);
    int mx = max(arr[i],arr[j]);
   if (arr[i]!=mx)
        changedDigit[i]=true ;
   else        changedDigit[j]=true;
    arr[i]=arr[j]=mx;//make these digits equal
    return 1+ConvertIntoPalindrome(i+1,j-1,arr,changedDigit);
}
int main(){
    int N,K; cin >> N >> K;
    string str; cin >> str;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        arr[i]=str[i]-'0';
    vector<bool> changedDigit(N,false);
    K-=ConvertIntoPalindrome(0,N-1,arr,changedDigit);
   if(K<0)
        cout<<"-1"<<endl;
    else
        maximizePalindrome(0,N-1,arr,changedDigit,K),print(arr);
    return 0;
}
