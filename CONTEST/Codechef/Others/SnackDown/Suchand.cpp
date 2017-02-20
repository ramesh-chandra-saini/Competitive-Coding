#include<bits/stdc++.h>
using namespace std;
vector<pair<int ,int > >a;
int ans=0;
int recursion(int start,int end,int b[],int k){
	if(b[end]-b[start]<=k)
		return 0;
	else
	 return (min(b[start]+recursion(start+1,end,b,k),b[end]-b[start]-k+recursion(start,end-1,b,k)));
}
int main()
{
	int i,j,k,l,n,b[28];
char s[100005];
scanf("%s",&s);
scanf("%d",&k);
n=strlen(s);
for(i=0;i<27;i++)
{
	b[i]=0;
}
for(i=0;i<n;i++)
{
	b[s[i]-'a']++;
}
sort(b,b+28);
printf("%d is ans",recursion(0,28-1,b,k));

return 0;
}
