#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int p[n];
    int j = p[0] = 0;
    for(int i = 1; i < n; i++)
    {
        while(j && s[i] != s[j])
            j = p[j - 1];
        if(s[i] == s[j])
            j++;
        p[i] = j;
    }
    while(n % (n - j))
        j = p[j - 1];
    int k = n - j;
    cout<<k<<endl;
    int m;
    cin >> m;
    cout << m / k % (1000000007) << "\n";
}
