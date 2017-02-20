#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked

void read(int &x){
    x=0;
    register char c=gc();
    for(;c<'0' || c>'9';c=gc());
    for(;c>='0' && c<='9';c=gc()){
        x=(x<<3)+(x<<1)+(c-'0');
    }
}
void write(int x){
    char buffer[35];
    register int i=-1;
    do{
        buffer[++i]='0'+x%10;x/=10;
    } while(x);
    while(i>=0){
        pc(buffer[i]);
        i--;
    }
    pc(' ');
}


#define ff first
#define ss second
#define MAX 100000000000000

using namespace std;

int n,m,tp,l,r;

vector <int> v[100005],prime;

int tree[400005],tree1[400005],a[100005];

int p[1000005];

void build(int node,int a,int b)
{
	if(a==b)
	{
		tree[node]=v[a][v[a].size()-1];
		return;
	}

	build(2*node,a,(a+b)/2);
	build(2*node+1,(a+b)/2+1,b);

	tree[node]=max(tree[2*node],tree[2*node+1]);
}

void build1(int node,int a,int b)
{
	if(a==b)
	{
		if(v[a].size()==1)
			tree1[node]=INT_MAX;
		else
			tree1[node]=a;

		return;
	}

	build1(2*node,a,(a+b)/2);
	build1(2*node+1,(a+b)/2+1,b);

	tree1[node]=min(tree1[2*node],tree1[2*node+1]);
}

int query(int node,int a,int b,int f,int l)
{
	if(a>b || a<1 || b>n || f>b || l<a)
		return 0;

	if(a>=f && b<=l)
		return tree[node];

	return max(query(2*node,a,(a+b)/2,f,l),query(2*node+1,(a+b)/2+1,b,f,l));
}

int query1(int node,int a,int b,int f,int l)
{
	if(a>b || a<1 || b>n || f>b || l<a)
		return INT_MAX;

	if(a>=f && b<=l)
		return tree1[node];

	return min(query1(2*node,a,(a+b)/2,f,l),query1(2*node+1,(a+b)/2+1,b,f,l));
}

void update(int node,int a,int b,int x)
{
	if(a>b || a<1 || b>n || x>b || x<a)
		return;

	if(a==b)
	{
		v[a].pop_back();
		tree[node]=v[a][v[a].size()-1];
		return;
	}

	update(2*node,a,(a+b)/2,x);
	update(2*node+1,(a+b)/2+1,b,x);

	tree[node]=max(tree[2*node],tree[2*node+1]);
}

void update1(int node,int a,int b,int x)
{
	if(a>b || a<1 || b>n || x>b || x<a)
		return;

	if(a==b)
	{
		tree1[node]=INT_MAX;
		return;
	}

	update1(2*node,a,(a+b)/2,x);
	update1(2*node+1,(a+b)/2+1,b,x);

	tree1[node]=min(tree1[2*node],tree1[2*node+1]);
}

int main()
{
    clock_t startTime = clock();

	int t;

	for(int i=2;i<=1000005;i++)
		p[i]=1;

	for(int i=2;i<=1005;i++)
	{
		if(!p[i])
			continue;

		for(int j=2*i;j<=1000005;j+=i)
			p[j]=0;
	}

	for(int i=2;i<=1000005;i++)
		if(p[i])
			prime.push_back(i);

	read(t);
	//cin >> t;

	while(t--)
	{
		read(n),read(m);
		//cin >> n >> m;

		for(int i=1;i<=n;i++)
			read(a[i]);
			//cin >> a[i];

		for(int i=1;i<=n;i++)
			v[i].clear();

		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<prime.size();j++)
			{
				while(a[i]>1 && a[i]%prime[j]==0)
				{
					a[i]/=prime[j];
					v[i].push_back(prime[j]);
				}

				if(a[i]==1)
					break;

				if(p[a[i]])
				{
					v[i].push_back(a[i]);
					a[i]=1;
					break;
				}
			}

			v[i].push_back(1);

			reverse(v[i].begin(),v[i].end());
		}

		build(1,1,n);
		build1(1,1,n);

		while(m--)
		{
			read(tp),read(l),read(r);
			//cin >> tp >> l >> r;

			if(tp)
			{
				write(query(1,1,n,l,r));
				//cout << query(1,1,n,l,r) << " ";
				continue;
			}

			while(1)
			{
				int ans=query1(1,1,n,l,r);

				if(ans==INT_MAX)
					break;

				update(1,1,n,ans);

				if(v[ans].size()==1)
					update1(1,1,n,ans);

				l=ans+1;

				if(l>r)
					break;
			}
		}
        pc('\n');
		//cout << endl;
	}
        clock_t endTime = clock();
        double duration = (double) (endTime-startTime)/CLOCKS_PER_SEC;

   cout<<duration<<endl;
	return 0;
}
