#include<bits/stdc++.h>
using  namespace std;
class Solution{
	public : vector<int> slidingMaximum(const vector<int> &A, int w);
};

#include<bits/stdc++.h>
vector<int> Solution::slidingMaximum(const vector<int> &A, int w) {
	bool debug=true;
	//if(debug){ cout<<"INPUT : "; for(int i=0;i<A.size();i++)cout<<A[i]<<"  ";  cout<<"window : "<<w;cout<<endl;}

    int n=A.size();vector<int>ans; ans.clear();
    if(n<=w){int mx=INT_MIN;for(int i=0;i<n;i++) mx=max(mx,A.at(i));ans.push_back(mx);return ans;}

    deque <int> L;L.clear();

    L.push_back(A.at(0));
    for(int i=1;i<w;i++) {

	    for(deque <int> :: iterator it=L.begin();it!=L.end();) {
	        if(*it<A.at(i)) {   L.erase(it);}
	        else ++it;
	    }
	    if(L.empty()) L.clear();
	    L.push_back(A.at(i));
	    if(debug) cout<<A.at(i)<<"  :: ";
    }
    if(debug) { cout<<"window : ["; for(int _i=0;_i<w;_i++)cout<<A[_i]<<" "; cout<<"]"<<endl;cout<<"Deque : ";for(deque<int> :: iterator it=L.begin();it!=L.end();it++) cout<<*it<<" "; cout<<endl;}
    for(int _i_=w;_i_<n;_i_++){
		ans.push_back(L.front());
		if(A.at(_i_-w)==L.front()) L.pop_front();

	    for(deque <int> :: iterator it=L.begin();it!=L.end();){
			if(*it<A.at(_i_)) { L.erase(it); }
	        else it++;
	    }
	    if(debug) cout<<A.at(_i_)<<"  :: ";
	    L.push_back(A.at(_i_));
		if(debug) { cout<<"window : ["; for(int _i=0;_i<w && _i<n;_i++)cout<<A[_i+_i_-w+1]<<" "; cout<<"]"<<endl;cout<<"Deque : ";for(deque<int> :: iterator it=L.begin();it!=L.end();it++) cout<<*it<<" ";cout<<endl;}
    }
    ans.push_back(L.front()); return ans;
}
//driver program
int main(){

	int t; cout<<"Test : "; cin>>t;
	while(t--){
	int n,val; cout<<"Size : ";cin>>n; //cout<<endl;
	vector<int> v;
	while(n--){
		cin>>val;
		v.push_back(val);
	}
	int w;cout<<"Window : "; cin>>w;
	Solution ob;
	vector<int> P=ob.slidingMaximum(v,w);
	cout<<"Ans : ";for(int i=0;i<P.size();i++)cout<<P[i]<<"  "; cout<<endl;
	}
	return 0;
}