
#include<bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

vector < pair<unsigned long long,unsigned long long> > v;

unsigned long long a[1000005];

int main()
{
	unsigned long long n,l,r,ans=0;

	cin >> n >> l >> r;

	for(int i=0;i<n;i++)
		cin >> a[i];

	sort(a,a+n);

	for(int i=0;i<n-1;i++)
		if(max(a[i+1]-a[i]+1,l)<=min(a[i+1]+a[i]-1,r))
			v.push_back(make_pair(max(a[i+1]-a[i]+1,l),min(a[i+1]+a[i]-1,r)));

	if(v.size())
		sort(v.begin(),v.end());

	unsigned long long left,right;

	if(v.size())
	{
		left=v[0].ff;
		right=v[0].ss;
	}

	for(int i=0;i<(int)v.size()-1;i++)
	{
		if(v[i].ff==v[i+1].ff)
			right=v[i+1].ss;
		else if(v[i+1].ff>v[i].ss)
		{
			ans+=right-left+1;
			left=v[i+1].ff;
			right=v[i+1].ss;
		}
		else
		{
			ans+=v[i+1].ff-left;
			left=v[i+1].ff;
			right=max(right,v[i+1].ss);
		}
	}

	if(v.size())
		ans+=right-left+1;

	cout << ans << endl;

	return 0;
}
