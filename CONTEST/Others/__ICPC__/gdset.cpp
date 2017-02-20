#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isGood(int n,int arr[]){
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
        if(arr[i+1]%arr[i])
            return false;
    return true;
}
bool isGood(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    for(int i=0;i<n-1;i++)
        if(arr[i+1]%arr[i])
            return false;
    return true;
}
ll BF(ll n,int arr[]){
    ll N = (1LL<<n);
        ll ans = 0;
        for(ll i=1;i<N;i++){
            ll temp = i;
            vector<int> curr; curr.empty();
            for(int j=0;temp;temp/=2LL,j++)
                if(temp%2LL)
                    curr.push_back(arr[j]);
             bool check = true;cout<<check<<" --> ";for(int j=0;j<curr.size();j++) cout<<curr[j]<<" "; cout<<endl;
            sort(curr.begin(),curr.end());

            for(int k=0;k<curr.size()-1;k++)
                if(arr[k+1]%arr[k])
                    check= false;

            ans+=(check)?1:0;
        }
        return ans;
}


#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pob pop_back

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

vector <long long> v[1000005];

long long a[1000005],dp[1000005],h[1000005];

int opti(int n,int a[])
{



		for(int i=0;i<n;i++)
			h[a[i]]=1;

		sort(a,a+n);

		for(int i=0;i<n;i++)
		{
			for(int j=1;j*j<=a[i];j++)
			{
				if(h[j] && j!=a[i] && a[i]%j==0)
					v[i].pb(j);

				if(h[a[i]/j] && j!=a[i]/j && j!=1 && a[i]%j==0)
					v[i].pb(a[i]/j);
			}
		}

		for(int i=0;i<n;i++)
		{
			dp[a[i]]=1;

			for(int j=0;j<v[i].size();j++)
				dp[a[i]]+=dp[v[i][j]];

			/*if(a[i]==5)
				for(int j=0;j<v[i].size();j++,cout<<endl)
					cout << v[i][j] << " ";

			cout << a[i] << " " << dp[a[i]] << endl; */
		}

		long long ans=0;

		for(int i=0;i<n;i++)
			ans+=dp[a[i]];

		return ans ;

}

int main(){
    int t; cin >> t;

    while(t--){
        int n;    cin >> n;
        int arr[n];for(int i=0;i<n;i++) cin >> arr[i];
        ll bf = BF(n,arr);
        ll opt = 0;//opti(n,arr);
        cout<<bf<<endl;
        /*if(opt!=bf){
            cout<<n<<" ";for(int j=0;j<n;j++) cout<<arr[j]<<" "; cout<<endl;
            break;
        }*/
    }

}
