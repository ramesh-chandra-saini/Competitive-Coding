#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define mod 1000000007
#define ll long long
using namespace std;

long long power(long long a,long long b)
{
    long long ret=1;

    while(b)
    {
        if(b&1)
            ret=(ret*a);

        b/=2;

        a=(a*a);
    }
    return ret;
}

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
bool isGood(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    for(int i=0;i<n-1;i++)
        if(arr[i+1]%arr[i])
            return false;
    return true;
}

ll BF(ll n,ll arr[]){
    ll N = (1LL<<n);
        ll ans = 0;
        for(ll i=1;i<N;i++){
            ll temp = i;
            vector<int> curr; curr.empty();
            for(int j=0;temp;temp/=2LL,j++)
                if(temp%2LL)
                    curr.push_back(arr[j]);
             bool check = isGood(curr);//cout<<check<<" --> ";for(int j=0;j<curr.size();j++) cout<<curr[j]<<" "; cout<<endl;
            ans+=(check)?1:0;
        }
        return ans;
}

set< long long> v[1000005];

long long a[1000005],dp[1000005],h[1000005];

int main()
{
	int t;

	cin >> t;

	while(t--)
	{
		long long n;

		scanf("%lld",&n);

		for(int i=0;i<n;i++)
			scanf("%lld",a+i);

		for(int i=0;i<n;i++)
			h[a[i]]=1;

		sort(a,a+n);

		for(int i=0;i<n;i++)
		{
			for(int j=2*a[i];j<=a[n-1];j+=a[i])
				if(h[j])
				{
					v[j].insert(a[i]);
					//cout << j << " " << a[i] << endl;
				}
		}

		/*for(int i=0;i<n;i++)
		{
			for(int j=1;j*j<=a[i];j++)
			{
				if(h[j] && j!=a[i] && a[i]%j==0)
					v[i].pb(j);

				if(h[a[i]/j] && j!=a[i]/j && j!=1 && a[i]%j==0)
					v[i].pb(a[i]/j);
			}
		}*/

		for(int i=0;i<n;i++)
		{
			dp[a[i]]=1;

            for(set<long long>::iterator it = v[a[i]].begin();it!=v[a[i]].end();++it)
                dp[a[i]]=(dp[a[i]]+dp[*it]);


			/*if(a[i]==10)
				for(int j=0;j<v[i].size();j++,cout<<endl)
					cout << v[i][j] << " ";

			cout << a[i] << " " << dp[a[i]] << endl;*/
		}

		long long ans=0;

		for(int i=0;i<n;i++)
			ans=(ans+dp[a[i]]);
        ans%=mod;
		while(ans<0)
			ans+=mod;

		printf("%lld\n",ans%mod);

		//cout << BF(n,a) << endl;

		for(int i=0;i<n;i++)
		{
			h[a[i]]=0;
			dp[a[i]]=0;
			v[a[i]].clear();
		}
	}

	return 0;
}
