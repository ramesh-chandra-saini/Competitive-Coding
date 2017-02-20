vector<int> Solution::slidingMaximum(const vector<int> &A, int w) {

    int n=A.size();

    vector<int>ans; ans.clear();

    if(n<=w){
		int mx=INT_MIN;

		for(int i=0;i<n;i++)
			mx=max(mx,A.at(i));
		ans.push_back(mx);
		return ans;
	}

	int head=0,end=0;
	int S[n+1];
	S[head]=A.at(0); end++;
    for(int i=1;i<w;i++) {

	    int _i=head;
	    for(int _k=head;_k<end;_k++){

			if(S[_k]>=A.at(i)){
				S[_i]=S[_k]; _i++;
			}
	    }
	    S[_i]=A.at(i);
	    end=_i;end++;
    }
    for(int i=w;i<n;i++){

		ans.push_back(S[head]);

		if(A.at(i-w)==S[head]) head++;
	    int _i=head;
	    for(int _k=head;_k<end;_k++){

			if(S[_k]>=A.at(i)){
				S[_i]=S[_k]; _i++;
			}
	    }
	    S[_i]=A.at(i);
	    end=_i;end++;

    }

    ans.push_back(S[head]);
    return ans;
}