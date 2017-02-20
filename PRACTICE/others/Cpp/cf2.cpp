#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,a,b;
	cin >> n;
	vector<pair<int,int> > M,F;
	char c;

	for(int i=0;i<n;i++){
		cin >> c >> a >> b;
		if(c=='M') M.push_back(make_pair(a,b));
		else 	F.push_back(make_pair(a,b));
	}

	int m[367],f[367];
	for(int i=1;i<=366;i++)
		m[i]=f[i]=0;
	for(int i=1;i<=366;i++){

		for(int j=0;j<M.size();j++){

			if( M[j].first<=i && i<=M[j].second){
				m[i]++;
            }
        }
		for(int j=0;j<F.size();j++){
			if( F[j].first<=i && i<=F[j].second){
				f[i]++;
            }
        }
	}
	int ans=0;
	for(int i=1;i<=366;i++)
			ans=max(ans,min(f[i],m[i]));
	cout<<(ans*2)<<endl;
	return 0;
}
